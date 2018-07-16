#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char map[26][26];
bool visit[26][26];
int cnt_idx;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N;
int cnt;

void dfs(int x, int y)
{
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visit[ny][nx] || map[ny][nx] == '0') continue;
		cnt++;
		dfs(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	cnt_idx = 0;
	vector<int> cnt_house;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && visit[i][j] == 0) {
				cnt = 1;
				dfs(j, i);
				cnt_house.push_back(cnt);
				cnt_idx++;
			}
		}
	}
	sort(cnt_house.begin(), cnt_house.end());
	cout << cnt_idx << '\n';
	for (int i = 0; i < cnt_idx; i++) {
		cout << cnt_house[i] << '\n';
	}
	return 0;
}