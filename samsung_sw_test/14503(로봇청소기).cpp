#include <cstdio>
#include <utility>
using namespace std;

int N, M;
int map[50][50];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


bool clean_check(int dir, int cur_x, int cur_y) {
	bool go = false;
	if (dir == 0) {
		if (map[cur_x - 1][cur_y] == 0) {
			go = true;
		}
	}
	else if (dir == 1) {
		if (map[cur_x][cur_y + 1] == 0) {
			go = true;
		}
	}
	else if (dir == 2) {
		if (map[cur_x + 1][cur_y] == 0) {
			go = true;
		}
	}
	else {
		if (map[cur_x][cur_y - 1] == 0) {
			go = true;
		}
	}
	return go;
}

bool go_back(int dir, int x, int y) {
	bool not_back = false;
	if (dir == 0) {
		if (map[x + 1][y] == 1) not_back = true;
	}
	else if (dir == 1) {
		if (map[x][y - 1] == 1) not_back = true;
	}
	else if (dir == 2) {
		if (map[x - 1][y] == 1) not_back = true;
	}
	else {
		if (map[x][y + 1] == 1) not_back = true;
	}
	return not_back;
}


int clean(pair<pair<int, int>, int> l) {
	int count = 0;
	int current_x, current_y, current_dir;
	int next_x, next_y, next_dir;
	bool turn_off = false;
	current_x = l.first.first; current_y = l.first.second;
	current_dir = l.second;

	//0은 빈 방, 1은 벽, 2는 청소한 곳
	while (!turn_off) {
		if (map[current_x][current_y] != 2) {		// 1번 우선 자기 자리를 청소한다.
			map[current_x][current_y] = 2;
			count++;
		}

		bool not_go = true;
		for (int i = 0; i < 4; i++) {
			int x = current_x + dx[i];
			int y = current_y + dy[i];
			if (map[x][y] == 0) {
				not_go = false;
				break;
			}

		}

		if (!not_go) {	//갈 곳이 있다면
			next_dir = (current_dir + 3) % 4;		// 다음 방향 설정
			if (!clean_check(next_dir, current_x, current_y)) {	// 왼쪽 방향에서 청소할 공간이 없다면 다시 2번으로 돌아간다.
				current_dir = next_dir;
				continue;
			}
			else {							//이동
				if (next_dir == 0) {
					current_x = current_x - 1; current_y = current_y;
				}
				else if (next_dir == 1) {
					current_x = current_x; current_y = current_y + 1;
				}
				else if (next_dir == 2) {
					current_x = current_x + 1; current_y = current_y;
				}
				else {
					current_x = current_x; current_y = current_y - 1;
				}
				current_dir = next_dir;
				continue;
			}
		}
		else {
			if (go_back(current_dir, current_x, current_y)) {
				turn_off = true;
				continue;
			}
			else {
				next_dir = current_dir;
				if (current_dir == 0) {
					current_x += 1;
				}
				else if (current_dir == 1) {
					current_y -= 1;
				}
				else if (current_dir == 2) {
					current_x -= 1;
				}
				else {
					current_y += 1;
				}
				continue;
			}
		}
	}
	return count;
}

int main() {
	int temp_x, temp_y, dir;
	pair<pair<int, int>, int>location;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &temp_x, &temp_y, &dir);
	location = make_pair(make_pair(temp_x, temp_y), dir);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int answer = clean(location);
	printf("%d\n", answer);

	return 0;
}