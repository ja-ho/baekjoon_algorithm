#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;

char map[101][101];
bool visit[101][101];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int answer;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = true;
	while (!q.empty()) {
		int q_length = q.size();
		while (q_length--) {
			int cx = q.front().first;
			int cy = q.front().second;

			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx == m - 1 && ny == n - 1) {
					answer++;
					return;
				}
				if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
				if (map[ny][nx] == '0' || visit[ny][nx]) continue;
				
				visit[ny][nx] = true;
				q.push(make_pair(nx, ny));
			}
		}
		answer++;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	answer = 1;
	bfs(0, 0);
	cout << answer << '\n';
	return 0;
}