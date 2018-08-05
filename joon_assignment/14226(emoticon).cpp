#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int d[1001][1001];

void bfs(int s)
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	d[1][0] = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int temp_clip = q.front().second;
		q.pop();
		if (d[now][now] == -1) {
			d[now][now] = d[now][temp_clip] + 1;
			q.push(make_pair(now, now));
		}
		if (now + temp_clip <= s && d[now + temp_clip][temp_clip] == -1) {
			d[now + temp_clip][temp_clip] = d[now][temp_clip] + 1;
			q.push(make_pair(now + temp_clip, temp_clip));
		}
		if (now - 1 >= 0 && d[now - 1][temp_clip] == -1) {
			d[now - 1][temp_clip] = d[now][temp_clip] + 1;
			q.push(make_pair(now - 1, temp_clip));
		}
	}
}

int main() {
	int s;
	cin >> s;
	memset(d, -1, sizeof(d));
	bfs(s);
	int ans = -1;
	for (int i = 0; i <= s; i++) {
		if (d[s][i] != -1) {
			if (ans == -1 || ans > d[s][i]) ans = d[s][i];
		}
	}
	cout << ans << '\n';
	return 0;
}