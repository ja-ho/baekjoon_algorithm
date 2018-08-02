#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[101];
long long d[101][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1][a[1]] = 1;

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + a[i] <= 20) {
				d[i][j] += d[i - 1][j + a[i]];
			}
			if (j >= a[i]) {
				d[i][j] += d[i - 1][j - a[i]];
			}
		}
	}
	cout << d[n - 1][a[n]] << '\n';
	return 0;
}