#include <iostream>
using namespace std;

int Answer;
int map[100][100];

int find_start(int end)
{
	int start;
	int x, y;
	x = end; y = 99;
	while (true) {
		if (y == 0 && map[y][x] == 1) {	//목적지 도착
			start = x;
			break;
		}

		if (x + 1 < 100 && map[y][x + 1] == 1) {	//오른쪽 분기점
			while (x + 1 < 100 && map[y][x + 1] == 1) {
				x += 1;
			}
		}

		else if (x - 1 >= 0 && map[y][x - 1] == 1) {
			while (x - 1 >= 0 && map[y][x - 1] == 1) {
				x -= 1;
			}
		}

		y -= 1;
	}

	return start;
}

int main() {
	int T;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> T;
		int end;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int position;
				cin >> position;
				if (i == 99) {
					if (position == 2) {
						end = j;
					}
				}
				map[i][j] = position;
			}
		}

		Answer = find_start(end);

		cout << "#" << T << " " << Answer << endl;
	}
	return 0;
}