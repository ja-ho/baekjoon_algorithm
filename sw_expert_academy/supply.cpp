#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int Answer;
int map[101][101];
int dp[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int min_dist;
int N;

void find_dp()
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(1, 1)));
	dp[1][1] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (y == N && x == N) break;

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N) {
				int next_dist = dist + map[next_y][next_x];
				if (dp[y][x] + map[next_y][next_x] < dp[next_y][next_x]) {
					dp[next_y][next_x] = dp[y][x] + map[next_y][next_x];
					pq.push(make_pair(-next_dist, make_pair(next_x, next_y)));
				}
			}
		}
	}
}

int main() {
	int T, tc;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Answer = 0;

		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%1d", &map[i][j]);
			}
		}


		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				dp[i][j] = 100000000;
			}
		}
		find_dp();

		cout << "#" << tc << " " << dp[N][N] << endl;
	}
	return 0;
}