#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

char map[10][10];
char copy_map[10][10];
vector<int>score;
int N, M;


int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

pair<int, int>hole;

void dfs(pair<int, int>red, pair<int, int>blue, char temp_map[10][10], int temp_count, int isSame) {
	//조건 체크. 빨간공 파란공이 hole로 들어가는지
	copy_map[10][10];
	if (temp_count > 10) {	//10번 초과면 return
		return;
	}
	if (blue.first == hole.first && blue.second == hole.second) return;		//파란공 들어가면 return
	if (red.first == hole.first && red.second == hole.second) {			//빨간 공 들어가면 return
		score.push_back(temp_count);
		return;
	}

	if (isSame == 2) {	//같은 곳 두번가도 return
		return;
	}

	//공굴리기
	for (int i = 0; i < 4; i++) {
		int next_red_x = red.first;
		int next_red_y = red.second;
		int next_blue_x = blue.first;
		int next_blue_y = blue.second;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				copy_map[j][k] = temp_map[j][k];
			}
		}
		/////
		//순서를 둔다 빨간공 먼저
		while (true) {
			if (copy_map[next_red_x + dx[i]][next_red_y + dy[i]] == '.') {	//빨간 공 빈칸
				if (copy_map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '.') {	//파란공도 이동 가능
					next_red_x += dx[i]; next_red_y += dy[i];
					next_blue_x += dx[i]; next_blue_y += dy[i];
					copy_map[next_red_x][next_red_y] = '.';
					copy_map[next_blue_x][next_blue_y] = '.';
					copy_map[next_red_x+dx[i]][next_red_y+dy[i]] = 'R';
					copy_map[next_blue_x+dx[i]][next_blue_y+dy[i]] = 'B';
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '#') {	//파란공은 벽에 막힘
					if (next_red_x + dx[i] == blue.first && next_red_y + dy[i] == blue.second) {	//빨간공 다음경로가 파란공
						if (isSame<2) {
							isSame++;
							break;
						}
						else return;
					}
					next_red_x += dx[i]; next_red_y += dy[i];
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == 'O') {	//파란공은 홀
					next_red_x += dx[i]; next_red_y += dy[i];
					next_blue_x += dx[i]; next_blue_y += dy[i];
					break;
				}
			}
			else if (map[next_red_x + dx[i]][next_red_y + dy[i]] == '#') {	//빨간 공 벽
				if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '.') {	//파란공은 이동 가능
					next_blue_x += dx[i]; next_blue_y += dy[i];
					copy_map[next_blue_x][next_blue_y] = '.';
					copy_map[next_blue_x + dx[i]][next_blue_y + dy[i]] = 'B';
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '#') {	//파란공은 벽에 막힘
					if (isSame<2) {
						isSame++;	
						break;
					}
					else return; //두번 이상 같은 곳
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == 'O') {	//파란공은 홀
					next_blue_x += dx[i]; next_blue_y += dy[i];
					break;
				}
				else if (next_blue_x + dx[i] == red.first && next_blue_y + dy[i] == red.second) {//파란공이 빨간공 있는 곳으로
					if (isSame < 2) {
						isSame++;
						break;
					}
					else return; //두번이상 같은 곳
				}
			}
			else if (map[next_red_x + dx[i]][next_red_y + dy[i]] == 'O') {	//빨간 공이 홀
				if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '.') {	//파란공은 이동 가능
					next_blue_x += dx[i]; next_blue_y += dy[i];
					copy_map[next_red_x][next_red_y] = '.';
					copy_map[next_blue_x][next_blue_y] = '.';
					copy_map[next_blue_x + dx[i]][next_blue_y + dy[i]] = 'B';
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '#') {	//파란공은 벽
					next_red_x += dx[i]; next_red_y += dy[i];
					break;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == 'O') {	//파란공도 홀
					next_red_x += dx[i]; next_red_y += dy[i];
					next_blue_x += dx[i]; next_blue_y += dy[i];
					break;
				}
			}
		}
		pair<int, int>next_red = make_pair(next_red_x, next_red_y);
		pair<int, int>next_blue = make_pair(next_blue_x, next_blue_y);
		dfs(next_red, next_blue, temp_map, temp_count + 1, isSame);
	}
}


int main() {
	pair<int, int>red;
	pair<int, int>blue;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') red = make_pair(i, j);
			if (map[i][j] == 'B') blue = make_pair(i, j);
			if (map[i][j] == 'O') hole = make_pair(i, j);
		}
	}

	dfs(red, blue, map, 0, 0);

	int MIN = 99999999;
	int length = score.size();
	if (length == 0) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < length; i++) {
			if (score[i] < MIN) {
				MIN = score[i];
			}
		}
		cout << MIN << endl;
	}
	return 0;
}