#include <cstdio>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

char map[51][51];
int water[51][51];
int d[51][51];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int R, C;

int BFS();


int main() {


	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", map[i]);
	}

	int answer = BFS();
	if (answer == -1) {
		printf("KAKATUS\n");
	}
	else {
		printf("%d", answer);
	}

	return 0;
}


int BFS()
{
	pair<int, int> initialPosition;
	pair<int, int> exitLocation;
	memset(water, -1, sizeof(water));
	memset(d, -1, sizeof(d));
	queue < pair<int, int>> q;

	//find the spot
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				q.push(make_pair(i, j));
				water[i][j] = 0;
			}
			else if (map[i][j] == 'D') {
				exitLocation = make_pair(i, j);
			}
			else if (map[i][j] == 'S') {
				initialPosition = make_pair(i, j);
			}
		}
	}

	//fill the water
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX > 0 && nextX <= R && nextY > 0 && nextY <= C) {	//Todo : check R, C position
				if (water[nextX][nextY] == -1 && map[nextX][nextY] != 'D' && map[nextX][nextY] != 'X') {
					water[nextX][nextY] = water[x][y] + 1;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}

	q.push(initialPosition);
	d[initialPosition.first][initialPosition.second] = 0;

	//find the path
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX > 0 && nextX <= R && nextY > 0 && nextY <= C) {
				if (map[nextX][nextY] != 'X' && d[nextX][nextY] == -1) {
					if (water[nextX][nextY] != -1 && d[x][y] + 1 < water[nextX][nextY]) {		//Todo: add water[nextX][nextY] != -1
						d[nextX][nextY] = d[x][y] + 1;
						q.push(make_pair(nextX, nextY));
					}
				}
			}
		}
	}
	int x, y;
	tie(x, y) = exitLocation;
	return d[x][y];
}
