#include <iostream>
#include <queue>
#include <utility>
using namespace std;


int w, h;
int map[51][51];
bool visit[51][51];
int cnt;

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (map[ny][nx] == 0 || visit[ny][nx]) continue;
			visit[ny][nx] = true;
			q.push(make_pair(nx, ny));
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					bfs(j, i);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}