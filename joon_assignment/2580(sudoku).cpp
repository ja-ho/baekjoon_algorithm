#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int map[10][10];
bool c_1[10][10];
bool c_2[10][10];
bool c_3[10][10];

bool check(int r, int c, int value)
{
	if (c_1[r][value]) return false;
	if (c_2[c][value]) return false;
	if (c_3[(r / 3) * 3 + (c / 3)][value]) return false;
	return true;
}

void go(int index)
{
	int cnt = 0;
	if (index == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	int r = index / 9;
	int c = index % 9;
	if (map[r][c] != 0) {
		go(index + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (check(r, c, i)) {
				c_1[r][i] = true;
				c_2[c][i] = true;
				c_3[(r / 3) * 3 + (c / 3)][i] = true;
				map[r][c] = i;
				go(index + 1);
				map[r][c] = 0;
				c_1[r][i] = false;
				c_2[c][i] = false;
				c_3[(r / 3) * 3 + (c / 3)][i] = false;
			}
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				c_1[i][map[i][j]] = true;
				c_2[j][map[i][j]] = true;
				c_3[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
			}
		}
	}
	go(0);

	return 0;
}