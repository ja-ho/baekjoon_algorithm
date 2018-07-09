#include <iostream>
#include <algorithm>
using namespace std;

int score[100001][2];
int d[100001][3];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> score[j][i];
			}
		}
		d[0][0] = 0;
		d[0][1] = score[0][0];
		d[0][2] = score[0][1];
		for (int i = 1; i < n; i++) {
			d[i][0] = max(d[i - 1][1], d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + score[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + score[i][1];
		}

		int answer = 0;
		answer = max(d[n - 1][0], max(d[n - 1][1], d[n - 1][2]));
		cout << answer << '\n';		
	}
	return 0;
}