#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[10001];

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coin;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}


	for (int i = 0; i <= k; i++) {
		dp[i] = 100000;
	}
	
	dp[0] = 0;


	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 100000) {
		cout << -1 << endl;
	}
	else {
		cout << dp[k] << endl;
	}

	return 0;
}