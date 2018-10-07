#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int map[51][51];
bool visit[51][51];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool is_connect(int x, int y, int nx, int ny, int dir)
{
	if (dir == 0) {	//0 = 위, 1 = 오른쪽, 2 = 아래, 3 = 왼쪽
		if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7) {
			if (map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 7) return false;
		}
		return true;
	}
	else if (dir == 1) {
		if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5) {
			if (map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 5) return false;
		}
		return true;	
	}
	else if (dir == 2) {
		if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6) {
			if (map[nx][ny] == 3 || map[nx][ny] == 5 || map[nx][ny] == 6) return false;
		}
		return true;
	}
	else {
		if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7) {
			if (map[nx][ny] == 2 || map[nx][ny] == 6 || map[nx][ny] == 7) return false;
		}
		return true;
	}
}

int go(int x, int y, int n, int m, int time)
{
	int ret_cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	int time_idx = 0;
	while (!q.empty()) {
		int q_size = q.size();
		time_idx++;
		while (q_size--) {
			auto it = q.front();
			q.pop();
			int cx = it.first;
			int cy = it.second;
			ret_cnt++;

			for (int i = 0; i < 4; i++) {	//0 = 위, 1 = 오른쪽, 2 = 아래, 3 = 왼쪽
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (map[cx][cy] == 1) {
				}
				else if (map[cx][cy] == 2) {
					if (i == 1 || i == 3) continue;
				}
				else if (map[cx][cy] == 3) {
					if (i == 0 || i == 2) continue;
				}
				else if (map[cx][cy] == 4) {
					if (i == 2 || i == 3) continue;
				}
				else if (map[cx][cy] == 5) {
					if (i == 0 || i == 3) continue;
				}
				else if (map[cx][cy] == 6) {
					if (i == 0 || i == 1) continue;
				}
				else if (map[cx][cy] == 7) {
					if (i == 1 || i == 2) continue;
				}
				else {
					cout << "error" << '\n';
					return -1;
				}
				if (map[nx][ny] == 0) continue;
				if (!is_connect(cx, cy, nx, ny, i)) continue;
				if (visit[nx][ny]) continue;
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
		if (time_idx >= time) return ret_cnt;
	}
	return ret_cnt;
}

int main() {
	freopen("C:\\Users\\magic\\jaeho\\Project1\\Project1\\baekjoon_algorithm\\모의_sw_테스트\\input.txt", "r", stdin);
	int n, m;
	int r, c;
	int l;
	int t;
	int answer = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> r >> c >> l;
		answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}
		answer = go(r, c, n, m, l);

		cout << "#" << tc << ' ' << answer << '\n';
	}
	return 0;
}