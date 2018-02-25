#include <iostream>
#include <queue>
using namespace std;

int Answer;
bool map[100][100];
queue<int> starts;

int find_distance()
{
	int start;
	int temp_start;
	int x, y;
	int cnt;
	int min_cnt = 1000000000;
	while (!starts.empty()) {
		x = starts.front(); y = 0;
		temp_start = x;
		starts.pop();
		cnt = 0;
		while (true) {
			if (y == 99 && map[y][x] == 1) {	//목적지 도착
				break;
			}

			if (x + 1 < 100 && map[y][x + 1] == 1) {	//오른쪽 분기점
				while (x + 1 < 100 && map[y][x + 1] == 1) {
					x += 1;
					cnt++;
				}
			}

			else if (x - 1 >= 0 && map[y][x - 1] == 1) {	//왼쪽 분기점
				while (x - 1 >= 0 && map[y][x - 1] == 1) {
					x -= 1;
					cnt++;
				}
			}
			y += 1;		//좌우 이동이 없다면 내려간다
			cnt++;
		}
		if (min_cnt >= cnt) {
			start = temp_start;
			min_cnt = cnt;
		}
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
				if (i == 0) {
					if (position == true) {
						starts.push(j);
					}
				}
				if (position == 1) {
					map[i][j] = true;
				}
				else {
					map[i][j] = false;
				}
			}
		}

		Answer = find_distance();

		cout << "#" << T << " " << Answer << endl;
	}
	return 0;
}