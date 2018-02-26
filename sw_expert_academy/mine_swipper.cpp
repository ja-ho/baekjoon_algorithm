#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <string>
using namespace std;

//char map[302][302];
string map[302];

queue<pair<int, int>> mines;
int Answer;
int N;

int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int check_near_mines(int x, int y)
{
	int mines = 0;

	if (y - 1 >= 0 && x - 1 >= 0 && map[y - 1][x - 1] == '*') mines++;
	if (y - 1 >= 0 && map[y - 1][x] == '*') mines++;
	if (y - 1 >= 0 && x + 1 < N &&map[y - 1][x + 1] == '*') mines++;
	if (x - 1 >= 0 && map[y][x - 1] == '*') mines++;
	if (x + 1 < N && map[y][x + 1] == '*') mines++;
	if (y + 1 < N && x - 1 >= 0 && map[y + 1][x - 1] == '*') mines++;
	if (y + 1 < N && map[y + 1][x] == '*') mines++;
	if (y + 1 < N && x + 1 < N &&map[y + 1][x + 1] == '*') mines++;
	return mines;
}


int mine_counter()
{
	int clk = 0;
	int near_mine;
	queue<pair<int, int>> one_clk;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '.') {
				if (check_near_mines(j, i) == 0) {
					one_clk.push(make_pair(j, i));
					map[i][j] = '0';
					while (!one_clk.empty()) {
						int x = one_clk.front().first;
						int y = one_clk.front().second;
						one_clk.pop();
						for (int k = 0; k < 8; k++) {
							int next_x = x + dx[k];
							int next_y = y + dy[k];
							if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
							if (map[next_y][next_x] == '.') {
								if ((near_mine = check_near_mines(next_x, next_y)) > 0) {
									map[next_y][next_x] = near_mine + '0';
								}
								else {
									map[next_y][next_x] = '0';
									one_clk.push(make_pair(next_x, next_y));
								}
							}
						}
					}
					clk++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == '.') clk++;
		}
	}

	return clk;
}

int main() {
	int T, tc;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (tc = 1; tc <= T; tc++) {
		Answer = 0;
		cin >> N;

		//for (int i = 1; i <= N; i++) {
		//	getchar();
		//	for (int j = 1; j <= N; j++) {
		//		scanf("%1c", &map[i][j]);
		//	}
		//}

		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}


		Answer = mine_counter();
		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}