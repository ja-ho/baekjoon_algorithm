#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> nums(n + 1, 0);
	vector<int> sums(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	sums[1] = nums[1];
	for (int i = 1; i <= n; i++) {
		sums[i] = sums[i - 1] + nums[i];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << sums[j] - sums[i - 1] << '\n';
	}
	return 0;
}