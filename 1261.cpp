#include <cstdio>
#include <queue>
using namespace std;

int maze[111][111];
int d[111][111];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(int M, int N);

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &maze[i][j]);
			d[i][j] = -1;
		}
	}

	int ans = bfs(M, N);

	printf("%d\n", ans);

	return 0;
}

int bfs(int M, int N)
{
	queue<pair<int,int>> q;
	queue<pair<int, int>> next_q;
	q.push(make_pair(0,0));
	d[0][0] = 0;
	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = currentX + dx[i];
			int nextY = currentY + dy[i];

			if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < M) {
				if (d[nextX][nextY] == -1) {
					if (maze[nextX][nextY] == 0) {
						d[nextX][nextY] = d[currentX][currentY];
						q.push(make_pair(nextX, nextY));
					}
					else {
						d[nextX][nextY] = d[currentX][currentY] + 1;
						next_q.push(make_pair(nextX, nextY));
					}
				}
			}
		}
		if (q.empty()) {
			q = next_q;
			next_q = queue<pair<int, int>>();
		}
	}

	return d[M - 1][N - 1];
}