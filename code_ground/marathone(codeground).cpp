#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstring>
using namespace std;

#define inf 100000000

int Answer;
int m, n, k;

int dp[11][101][101];	//dp[k][n][m]
bool visit[11][101][101];


int diff(int a, int b) {
	return abs(abs(a) - abs(b));
}

vector<vector<int>> map;


int find_dp(int i, int j, int needed_water)
{
	if (visit[needed_water][i][j]) {
		return dp[needed_water][i][j];
	}

	if (i == n && j == m) {
		if (needed_water == 0)
			return 0;
		else return 10000000;
	}

	visit[needed_water][i][j] = true;
	dp[needed_water][i][j] = inf;


	if (j + 1 <= m) {
		if (map[i][j + 1] >= 0) {
 			dp[needed_water][i][j] = min(dp[needed_water][i][j], find_dp(i, j + 1, needed_water)
																+ diff(map[i][j], map[i][j + 1]));
		}

		else {
			if (needed_water > 0) {
				dp[needed_water][i][j] = min(dp[needed_water][i][j], find_dp(i, j + 1, needed_water - 1)
																+ diff(map[i][j], map[i][j + 1]));
			}
			else {
				dp[needed_water][i][j] = min(dp[needed_water][i][j], find_dp(i, j+ 1, needed_water)
																+ diff(map[i][j], map[i][j + 1]));
			}
		}
	}
	
	if (i + 1 <= n) {
		if (map[i + 1][j] >= 0) {
			dp[needed_water][i][j] = min(dp[needed_water][i][j], find_dp(i + 1, j, needed_water)
																+ diff(map[i][j], map[i + 1][j]));
		}

		else {
			if (needed_water > 0) {
				dp[needed_water][i][j] = min(dp[needed_water][i][j], find_dp(i + 1, j, needed_water - 1)
					+ diff(map[i][j], map[i + 1][j]));
			}
			else {
				dp[needed_water][i][j] = min(dp[needed_water][i][j], find_dp(i + 1, j, needed_water)
					+ diff(map[i][j], map[i + 1][j]));
			}
		}
	}
	return dp[needed_water][i][j];
}




int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		map.clear();
		scanf("%d %d %d", &m, &n, &k);
		map.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			map[i].resize(m + 1);
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		memset(visit, 0, sizeof(visit));

		Answer = find_dp(0, 0, k);

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}