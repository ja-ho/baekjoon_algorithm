#include <iostream>
#include <queue>
#include <utility>
using namespace std;


int n, m;
int map[1001][1001];
vector<pair<int, int>> rotten_tomato;
int answer;
int unrotten;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() 
{
	queue<pair<int, int>> q;
	int rotten_length = rotten_tomato.size();
	for (int i = 0; i < rotten_length; i++) {
		int x = rotten_tomato[i].first;
		int y = rotten_tomato[i].second;
		q.push(make_pair(x, y));
	}

	while (!q.empty()) {
		int q_length = q.size();
		while (q_length--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
				if (map[ny][nx] == -1 || map[ny][nx] == 1) continue;
				map[ny][nx] = 1;
				unrotten--;
				if (unrotten == 0) {
					answer++;
					return;
				}
				q.push(make_pair(nx, ny));
			}
		}
		answer++;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) 
				rotten_tomato.push_back(make_pair(j, i));
			else if (map[i][j] == 0) unrotten++;
		}
	}
	if (unrotten == 0) cout << 0 << '\n';
	else {
		bfs();
		if (unrotten != 0) {
			cout << -1 << '\n';
		}
		else {
			cout << answer << '\n';
		}	
	}
	return 0;
}