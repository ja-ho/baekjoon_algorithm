#include <iostream>
#include <vector>
using namespace std;

int dp[10001];

int main()
{
	int n, k;
	vector<int> coin;

	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coin[i] = temp;
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	cout << dp[k] << endl;

	return 0;
}