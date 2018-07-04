//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int dp[1000001];
//int N;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	dp[1] = 0;
//	for (int i = 2; i <= N; i++) {
//		dp[i] = min(min(dp[i-1] + 1, dp[]))
//	}
//	cout << dp[N] << '\n';
//	return 0;
//}

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int d[3111111];

int main() {
	int n;
	scanf("%d", &n);
	memset(d, 9999, sizeof(d));
	d[n] = 0;

	for (int i = n - 1; i >= 1; i--) {
		d[i] = min(min(d[i * 3], d[i * 2]), d[i + 1]) + 1;
	}
	printf("%d\n", d[1]);
	return 0;
}