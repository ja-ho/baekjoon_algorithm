#include <iostream>
#include <vector>
#include <cstring>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int num;
	long long sums = 0;
	long long ans = 0;
	long long remainder_[1000];
	memset(remainder_, 0, sizeof(remainder_));
	for (int i = 1; i <= n; i++) {
		cin >> num;
		sums = sums + num;
		if (!(sums % m)) {
			ans++;
		}
		remainder_[sums % m]++;
	}

	for (int i = 0; i < m; i++) {
		if (remainder_[i]) {
			ans += (remainder_[i] * (remainder_[i] - 1)) / 2;
		}
	}
	cout << ans << '\n';

	return 0;
}