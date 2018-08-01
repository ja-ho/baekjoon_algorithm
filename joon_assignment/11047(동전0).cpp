#include <iostream>
#include <vector>
using namespace std;

int coins[11];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		ans += k / coins[i];
		k %= coins[i];
	}

	cout << ans << '\n';
	return 0;
}