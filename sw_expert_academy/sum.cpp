#include <iostream>
using namespace std;

#define MAX(a, b)	((a) > (b) ? (a) : (b))

int map[101][101];

int Answer;

int go() 
{
	int max_horizontal = 0;
	int max_vertical = 0;
	int max_diagonal = 0;
	int return_max = 0;

	for (int i = 1; i <= 100; i++) {
		int temp_horizontal = 0;
		for (int j = 1; j <= 100; j++) {
			temp_horizontal += map[i][j];
		}
		if (max_horizontal < temp_horizontal) {
			max_horizontal = temp_horizontal;
		}
	}

	for (int i = 1; i <= 100; i++) {
		int temp_vertical = 0;
		for (int j = 1; j <= 100; j++) {
			temp_vertical += map[j][i];
		}
		if (max_vertical < temp_vertical) {
			max_vertical = temp_vertical;
		}
	}

	for (int i = 1; i <= 100; i++) {
		max_diagonal += map[i][i];
	}
	int temp_diagonal = 0;
	for (int i = 100; i >= 1; i--) {
		temp_diagonal += map[i][100 - i];
	}
	if (max_diagonal < temp_diagonal) max_diagonal = temp_diagonal;

	return_max = MAX(max_diagonal, max_horizontal);
	return_max = MAX(return_max, max_vertical);
	return return_max;
}

int main() {
	int tc;
	int T;
	freopen("input.txt", "r", stdin);
	for (tc = 1; tc <= 10; tc++) {
		Answer = 0;
		cin >> T;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> map[i][j];
			}
		}
		Answer = go();

		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}