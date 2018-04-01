#include <iostream>
#include <vector>
using namespace std;

char map[101][101];
int Answer;

bool find_vertical(int length)
{
	bool visit;
	for (int k = 1; k <= 100; k++) {
		for (int j = 1; j <= 100 - length + 1; j++) {
			visit = true;
			for (int i = 0; i < length / 2; i++) {
				if (map[j + i][k] != map[j + length - i - 1][k]) {
					visit = false;
					break;
				}
			}
			if (visit) {
				return true;
			}
		}
	}
	return false;
}

bool find_horizontal(int length)
{
	bool visit;
	for (int k = 1; k <= 100; k++) {
		for (int j = 1; j <= 100 - length + 1; j++) {
			visit = true;
			for (int i = 0; i < length / 2; i++) {
				if (map[k][j + i] != map[k][j + length - 1 - i]) {
					visit = false;
					break;
				}
			}
			if (visit) {
				return true;
			}
		}
	}
	return false;
}


int main()
{
	for (int tc = 1; tc <= 10; tc++) {
		Answer = 0;
		int temp;
		int T;
		cin >> T;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				char temp;
				cin >> temp;
				map[i][j] = temp;
			}
		}

		for (int i = 1; i <= 100; i++) {
			if (find_horizontal(i)) {
				Answer = i;
			}
			if (find_vertical(i)) {
				Answer = i;
			}
		}

		cout << "#" << T << " " << Answer << endl;
	}
	return 0;
}