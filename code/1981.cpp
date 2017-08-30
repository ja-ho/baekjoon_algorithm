#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int n;
int map[101][101];
bool visit[101][101];

int nx[] = { 1, -1, 0, 0 };
int ny[] = { 0, 0, 1, -1 };

bool bfs(int minimum, int maximum);
bool find(int diff);

int main() {
	int left = 0;
	int right = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (right < map[i][j]) {
				right = map[i][j];
			}
		}
	}

	int answer = right;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (find(mid)) {
			if (answer > mid) {	//todo: compare code	 answer = mid;  //it is not working
				answer = mid;
			}
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d", answer);

	return 0;
}

bool bfs(int minimum, int maximum)
{
	if (minimum > map[1][1] || maximum < map[1][1]) return false;
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> Next;
	Next.push(make_pair(1, 1));
	visit[1][1] = true;
	while (!Next.empty()) {
		int currentX, currentY;
		tie(currentX, currentY) = Next.front();
		Next.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = currentX + nx[i];
			int nextY = currentY + ny[i];

			if (nextX > 0 && nextX <= n && nextY > 0 && nextY <= n) {
				if (visit[nextX][nextY] == false) {
					if (minimum <= map[nextX][nextY] && maximum >= map[nextX][nextY]) {
						Next.push(make_pair(nextX, nextY));
						visit[nextX][nextY] = true;

					}
				}
			}
		}
	}

	return visit[n][n];
}

bool find(int diff)
{
	for (int minimum = 0; minimum + diff <= 200; minimum++) {
		if (bfs(minimum, minimum + diff)) {
			return true;
		}
	}
	return false;
}