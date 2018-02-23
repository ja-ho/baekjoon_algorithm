#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int Answer;
set<int> s;

int map[4][4];

void go(int i, int j, int move_cnt, int current)
{
	if (move_cnt == 7) {
		s.insert(current);
		return;
	}
	current *= 10;
	current += map[i][j];
	if (i + 1 < 4) {
		go(i + 1, j, move_cnt + 1, current);
	}
	if (i - 1 >= 0) {
		go(i - 1, j, move_cnt + 1, current);
	}
	if (j + 1 < 4) {
		go(i, j + 1, move_cnt + 1, current);
	}
	if (j - 1 >= 0) {
		go(i, j - 1, move_cnt + 1, current);
	}
}


int main() {
	int T, tc;
	cin >> T;

	for (tc = 0; tc < T; tc++) {
		s.clear();
		Answer = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				go(i, j, 0, 0);
			}
		}

		Answer = s.size();

		cout << "#" << tc + 1 << " " << Answer << endl;
	}
	return 0;
}