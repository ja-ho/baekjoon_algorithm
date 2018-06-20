#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m, x, y, k;
queue<int> command;	// 1 == µ¿, 2 == ¼­, 3 == ºÏ, 4 == ³²
vector<int> dice;	// 0 = À§, 1 = À§ 2 = ¿À¸¥, 3 = ¾Æ·¡ 4 = ¿Þ 5 = ¹Ù´Ú¸é

int map[22][22];
pair<int, int> start_point;

void roll(int dir)
{
	int temp;
	if (dir == 1) {
		temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	else if (dir == 2) {
		temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
	}
	else if (dir == 3) {
		temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	else {
		temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}
}


int go()
{
	int x = start_point.first;
	int y = start_point.second;
	while (!command.empty()) {
		int dir = command.front();
		command.pop();
		if (dir == 1) {
			if (y + 1 > m - 1) {
				continue;
			}
			else {
				roll(dir);
				if (map[x][y + 1] == 0) {
					map[x][y + 1] = dice[5];
				}
				else {
					dice[5] = map[x][y + 1];
					map[x][y + 1] = 0;
				}
				y++;
				printf("%d\n", dice[0]);
			}
		}
		else if (dir == 2) {
			if (y - 1 < 0) {
				continue;
			}
			else {
				roll(dir);
				if (map[x][y - 1] == 0) {
					map[x][y - 1] = dice[5];
				}
				else {
					dice[5] = map[x][y - 1];
					map[x][y - 1] = 0;
				}
				y--;
				printf("%d\n", dice[0]);
			}
		}
		else if (dir == 3) {
			if (x - 1 < 0) {
				continue;
			}
			else {
				roll(dir);
				if (map[x - 1][y] == 0) {
					map[x - 1][y] = dice[5];
				}
				else {
					dice[5] = map[x - 1][y];
					map[x - 1][y] = 0;
				}
				x--;
				printf("%d\n", dice[0]);
			}
		}
		else {
			if (x + 1 > n - 1) {
				continue;
			}
			else {
				roll(dir);
				if (map[x + 1][y] == 0) {
					map[x + 1][y] = dice[5];
				}
				else {
					dice[5] = map[x + 1][y];
					map[x + 1][y] = 0;
				}
				x++;
				printf("%d\n", dice[0]);
			}
		}
	}
	return 0;
}


int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	start_point = make_pair(x, y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		command.push(temp);
	}
	dice.clear();
	dice.resize(6);

	go();
	return 0;
}