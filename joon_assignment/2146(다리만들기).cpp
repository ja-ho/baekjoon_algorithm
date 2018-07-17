#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N;
int map[101][101];
int group[101][101];
int bridge[101][101];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	//group ¸¸µé±â
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && group[i][j] == 0) {
				group[i][j] = ++cnt;
				queue<pair<int, int>> q;
				q.push(make_pair(j, i));
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (map[ny][nx] == 1 && group[ny][nx] == 0) {
							group[ny][nx] = cnt;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bridge[i][j] = -1;
			if (map[i][j] == 1) {
				bridge[i][j] = 0;
				q.push(make_pair(j, i));
			}
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (bridge[ny][nx] == -1) {
				bridge[ny][nx] = bridge[cy][cx] + 1;
				group[ny][nx] = group[cy][cx];
				q.push(make_pair(nx, ny));
			}
		}
	}

	int answer = 1001;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int x = j + dx[k];
				int y = i + dy[k];
				if (x < 0 || x >= N || y < 0 || y >= N) continue;
				if (group[y][x] != group[i][j]) {
					if (answer > bridge[i][j] + bridge[y][x]) answer = bridge[i][j] + bridge[y][x];
				}
			}
		}
	}

	cout << answer << '\n';
	return 0;
}
