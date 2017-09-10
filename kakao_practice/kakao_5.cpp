#include<vector>
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int solution(vector<vector<int> > land)
{
	vector<vector<int>> dp;
	vector<int> v(4, 0);
	int land_length = land.size();
	for (int i=0; i<land_length; i++) {
		dp.push_back(v);
	}
	int answer = 0;
	//초기화
	for (int i = 0; i< 4; i++) {
		dp[0][i] = land[0][i];
	}

	//dp 채우기
	for (int i = 1; i< land_length; i++) {
		for (int j = 0; j<4; j++) {
			int max_row = 0;
			for (int k = 0; k<4; k++) {
				if (j == k) continue;
				else {
					if (max_row < dp[i - 1][k]) max_row = dp[i - 1][k];
				}
			}
			dp[i][j] = max_row + land[i][j];
		}
	}

	for (int i = 0; i<4; i++) {
		if (answer < dp[land_length - 1][i]) answer = dp[land_length - 1][i];
	}

	return answer;
}

int main() {
	vector<vector<int>> land;
	vector<int> v1 = { 1, 2, 3, 5 };
	vector<int> v2 = { 5, 6, 7, 8 };
	vector<int> v3 = { 4, 3, 2, 1 };
	land.push_back(v1);
	land.push_back(v2);
	land.push_back(v3);

	int answer = solution(land);
	printf("%d\n", answer);

	return 0;
}