#include <iostream>
using namespace std;

long long d[5001][5001];
int mod = 1000000000;

//O(kN^2)
//int main() {
//	int n, k;
//	cin >> n >> k;
//	d[0][0] = 1;
//
//	for (int i = 1; i <= k; i++) {
//		for (int j = 0; j <= n; j++) {
//			for (int m = 0; m <= j; m++) {
//				d[i][j] += d[i - 1][j - m];
//				d[i][j] %= mod;
//			}
//		}
//	}
//	cout << d[k][n] << '\n';
//	return 0;
//}

int main() {
	int n, k;
	cin >> n >> k;
	d[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			d[i][j] = d[i - 1][j];
			if (j - 1 >= 0) {
				d[i][j] += d[i][j - 1];
			}
			d[i][j] %= mod;
		}
	}
	cout << d[k][n] << '\n';
	return 0;
}