#include <iostream>
#include <cstring>
using namespace std;

int mode[101];


int main() {
	int t;
	int tc;

	for (tc = 0; tc < 10; tc++) {
		int answer = 0;
		int number_of_mode = 0;
		cin >> t;
		memset(mode, 0, sizeof(mode));

		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;
			mode[score]++;
		}

		for (int i = 0; i <= 100; i++) {
			if (mode[i] >= number_of_mode) {
				number_of_mode = mode[i];
				answer = i;
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}