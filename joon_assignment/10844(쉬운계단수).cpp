#include <iostream>
using namespace std;

long long d[101][10];

int mod_num = 1000000000;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) d[i][j] += d[i - 1][j - 1] % mod_num;
			if (j + 1 <= 9) d[i][j] += d[i - 1][j + 1] % mod_num;
			d[i][j] %= mod_num;
		}
	}


	long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += d[N][i] % mod_num;
	}
	answer %= mod_num;
	cout << answer << '\n';
	return 0;
}
