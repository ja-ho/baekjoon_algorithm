#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int map[501][501];
bool visit[501][501];
int answer;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int level, int score)
{
	if (level == 4) {
		if (answer < score) {
			answer = score;
			visit[y][x] = false;
		}
		return;
	}
	if (visit[y][x]) return;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (visit[ny][nx]) continue;
		dfs(nx, ny, level + 1, score + map[ny][nx]);
	}
	visit[y][x] = false;
	return;
}

void exception_handle(int x, int y)
{
	int sum = map[y][x];
	int cnt = 0;
	if (x + 1 < m) {
		sum += map[y][x + 1];
		cnt++;
	}
	if (x - 1 >= 0) {
		sum += map[y][x - 1];
		cnt++;
	}
	if (y + 1 < n) {
		sum += map[y + 1][x];
		cnt++;
	}
	if (y - 1 >= 0) {
		sum += map[y - 1][x];
		cnt++;
	}
	if (cnt <= 2) return;
	else if (cnt == 3) {
		if (sum > answer) answer = sum;
		return;
	}
	else if (cnt == 4) {
		int minimum_one = min(map[y][x + 1], min(map[y][x - 1], min(map[y + 1][x], map[y - 1][x])));
		sum -= minimum_one;
		if (sum > answer) answer = sum;
		return;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(j, i, 1, map[i][j]);
			exception_handle(j, i);
		}
	}
	cout << answer << '\n';
	return 0;
}