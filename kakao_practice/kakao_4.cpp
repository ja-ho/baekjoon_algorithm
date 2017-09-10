#include<vector>
using namespace std;

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int solution(vector<vector<int>> board)
{
	int answer = 0;
	vector<vector<int>> dp;
	int board_length = board.size();
	int col_length = board[0].size();
	vector<int> v(col_length, 0);
	for (int i = 0; i<board_length; i++) {
		dp.push_back(v);
	}
	for (int i = 0; i < board_length; i++) {
		for (int j = 0; j<col_length; j++) {
			if (i == 0 || j == 0) {
				if (board[i][j]) {
					dp[i][j] = 1;
					answer = answer > 1 ? answer : 1;
				}
			}
			else {
				if (board[i][j]) {
					dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
					if (answer < dp[i][j]) answer = dp[i][j];
				}
			}
		}
	}
	return answer * answer;
}
