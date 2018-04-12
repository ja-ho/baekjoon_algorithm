#include <cstdio>
#include <algorithm>
using namespace std;


int n, m;
int answer;

int score_map[505][505];
bool visit[505][505];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int level, int score)
{
	if (level == 4) {
		score += score_map[y][x];
		if (answer < score) {
			answer = score;
		}
		return;
	}
	visit[y][x] = true;
	score += score_map[y][x];
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (visit[ny][nx]) continue;	
		dfs(nx, ny, level + 1, score);
	}
	visit[y][x] = false;
	return; 
}

void exceptional_situation(int x, int y)
{
	int sum = 0;
	int min_4 = 9999;
	int idx = 0;
	sum += score_map[y][x];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		sum += score_map[ny][nx];
		min_4 = min(min_4, score_map[ny][nx]);
		idx++;
	}
	if (idx == 4) {
		sum -= min_4;
	}
	else if (idx <= 2) {
		return;
	}

	if (answer < sum) {
		answer = sum;
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &score_map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(j, i, 1, 0);
			exceptional_situation(j, i);
		}
	}
	printf("%d\n", answer);
	return 0;
}