#include <vector>
using namespace std;

int dp[100000][2][2];

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int solution(vector<int> sticker)
{
	int answer = 0;
	int sticker_length = sticker.size();
	dp[0][0][0] = 0;
	dp[0][1][0] = 0;
	dp[1][1][0] = sticker[1];
	dp[1][0][0] = 0;
	dp[2][0][0] = 0;
	dp[2][1][0] = sticker[2];

	dp[0][0][1] = sticker[0];
	dp[0][1][1] = sticker[0];
	dp[1][1][1] = sticker[0];
	dp[1][0][1] = sticker[0];
	dp[2][0][1] = sticker[0];
	dp[2][1][1] = sticker[0] + sticker[2];

	for (int i = 3; i<sticker_length; i++) {
		dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
		dp[i][1][0] = dp[i - 1][0][0] + sticker[i];
		dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);
		dp[i][1][1] = dp[i - 1][0][1] + sticker[i];
	}

	answer = max(dp[sticker_length - 1][1][0], dp[sticker_length - 1][0][0]);
	answer = max(answer, dp[sticker_length - 1][0][1]);
	answer = max(answer, dp[sticker_length - 1][1][1]);
	return answer;
}