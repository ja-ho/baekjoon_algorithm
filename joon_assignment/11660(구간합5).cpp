#include <iostream>
#include <vector>
using namespace std;

int nums[1025][1025];
int sums[1025][1025];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> nums[i][j];
			sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + nums[i][j];
		}
	}

	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << sums[c][d] - sums[a - 1][d] - sums[c][b - 1] + sums[a - 1][b - 1] << '\n';
	}
	return 0;
}