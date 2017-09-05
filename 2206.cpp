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
	if(answer == 0) printf("-1\n");
	else printf("%d\n", answer);

	return 0;
}

int bfs(int N, int M) 
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1,1,0));
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
				}				}
			}
		}
	}

	return visit[N][M];
}
