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
	//���� üũ. ������ �Ķ����� hole�� ������
	copy_map[10][10];
	if (temp_count > 10) {	//10�� �ʰ��� return
		return;
	}
	if (blue.first == hole.first && blue.second == hole.second) return;		//�Ķ��� ���� return
	if (red.first == hole.first && red.second == hole.second) {			//���� �� ���� return
		score.push_back(temp_count);
		return;
	}

	if (isSame == 2) {	//���� �� �ι����� return
		return;
	}

	//��������
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
		//������ �д� ������ ����
		while (true) {
			if (copy_map[next_red_x + dx[i]][next_red_y + dy[i]] == '.') {	//���� �� ��ĭ
				if (copy_map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '.') {	//�Ķ����� �̵� ����
					next_red_x += dx[i]; next_red_y += dy[i];
					next_blue_x += dx[i]; next_blue_y += dy[i];
					copy_map[next_red_x][next_red_y] = '.';
					copy_map[next_blue_x][next_blue_y] = '.';
					copy_map[next_red_x+dx[i]][next_red_y+dy[i]] = 'R';
					copy_map[next_blue_x+dx[i]][next_blue_y+dy[i]] = 'B';
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '#') {	//�Ķ����� ���� ����
					if (next_red_x + dx[i] == blue.first && next_red_y + dy[i] == blue.second) {	//������ ������ΰ� �Ķ���
						if (isSame<2) {
							isSame++;
							break;
						}
						else return;
					}
					next_red_x += dx[i]; next_red_y += dy[i];
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == 'O') {	//�Ķ����� Ȧ
					next_red_x += dx[i]; next_red_y += dy[i];
					next_blue_x += dx[i]; next_blue_y += dy[i];
					break;
				}
			}
			else if (map[next_red_x + dx[i]][next_red_y + dy[i]] == '#') {	//���� �� ��
				if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '.') {	//�Ķ����� �̵� ����
					next_blue_x += dx[i]; next_blue_y += dy[i];
					copy_map[next_blue_x][next_blue_y] = '.';
					copy_map[next_blue_x + dx[i]][next_blue_y + dy[i]] = 'B';
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '#') {	//�Ķ����� ���� ����
					if (isSame<2) {
						isSame++;	
						break;
					}
					else return; //�ι� �̻� ���� ��
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == 'O') {	//�Ķ����� Ȧ
					next_blue_x += dx[i]; next_blue_y += dy[i];
					break;
				}
				else if (next_blue_x + dx[i] == red.first && next_blue_y + dy[i] == red.second) {//�Ķ����� ������ �ִ� ������
					if (isSame < 2) {
						isSame++;
						break;
					}
					else return; //�ι��̻� ���� ��
				}
			}
			else if (map[next_red_x + dx[i]][next_red_y + dy[i]] == 'O') {	//���� ���� Ȧ
				if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '.') {	//�Ķ����� �̵� ����
					next_blue_x += dx[i]; next_blue_y += dy[i];
					copy_map[next_red_x][next_red_y] = '.';
					copy_map[next_blue_x][next_blue_y] = '.';
					copy_map[next_blue_x + dx[i]][next_blue_y + dy[i]] = 'B';
					continue;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == '#') {	//�Ķ����� ��
					next_red_x += dx[i]; next_red_y += dy[i];
					break;
				}
				else if (map[next_blue_x + dx[i]][next_blue_y + dy[i]] == 'O') {	//�Ķ����� Ȧ
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