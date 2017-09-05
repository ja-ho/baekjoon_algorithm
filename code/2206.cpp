#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

int map[1001][1001];
int d[1001][1001][2];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int N, int M); 

int main() {
	int N, M;
	int answer = 0;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++){
			scanf("%1d", &map[i][j]);
		}		
	}
		
	answer = bfs(N, M);
	printf("%d\n", answer);

	return 0;
}

int bfs(int N, int M) 
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1,1,0));
	d[1][1][0] = 1;
	while(!q.empty()) {
		int currentX, currentY, isBreak;
		tie(currentX, currentY, isBreak) = q.front();
		q.pop();

		for(int i=0; i<4; i++) {
			int nextX = currentX + dx[i];
			int nextY = currentY + dy[i];
			if(nextX > 0 && nextX <= N && nextY > 0 && nextY <= M) {
				if(map[nextX][nextY] == 0 && d[nextX][nextY][isBreak] == 0) {
					d[nextX][nextY][isBreak] = d[currentX][currentY][isBreak] + 1; 
					q.push(make_tuple(nextX, nextY, isBreak));
				}

				if(isBreak == 0 && map[nextX][nextY] == 1 && d[nextX][nextY][isBreak] == 0) {
					d[nextX][nextY][isBreak + 1] = d[currentX][currentY][isBreak] + 1;
					q.push(make_tuple(nextX, nextY, isBreak + 1));
				}
			}
		}
	}
	int answer;

	if(d[N][M][0]!= 0 && d[N][M][1]!=0) {
		answer = min(d[N][M][0], d[N][M][1]);
	} else if (d[N][M][0]!=0) {
		answer = d[N][M][0];
	} else if (d[N][M][1]!=0) {
		answer = d[N][M][1];
	} else answer = -1;


	return answer;
}
