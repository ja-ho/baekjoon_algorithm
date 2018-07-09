#include <iostream>
using namespace std;

int d[1001][10];
int mod_num = 10007;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
			d[i][j] %= mod_num;
		}
	}

	int answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += d[N][i] % mod_num;
	}
	answer %= mod_num;
	cout << answer << '\n';
	return 0;
}