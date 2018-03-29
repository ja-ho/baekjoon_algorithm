#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, K;



int main()
{
	int temp_index=0;
	int coin_count = 0;
	cin >> N >> K;
	vector<int> coins;
	int* dp;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp > K) break;
		coins.push_back(temp);
	}
	int coin_length = coins.size();

	for (int i = coin_length - 1; i >= 0; i--) {
		if (K == 0) break;
		while (K >= 0) {
			if (K < coins[i]) break;
			K -= coins[i];
			coin_count++;
		}
	}




	//dp = (int *)malloc(sizeof(int)*(K+1));

	//fill(&dp[0], &dp[K]+1, 1000000000);

	//for (int i = 0; i < temp_index; i++) {
	//	dp[coins[i]] = 1;
	//}
	//for (int i = 0; i < temp_index; i++) {
	//	for (int j = coins[i]; j <= K; j++) {
	//		dp[j] = min(dp[j], dp[j - coins[i]] + 1);
	//	}
	//}

	cout << coin_count << endl;
	return 0;
}