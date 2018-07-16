#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n;
int map[101][101];
int visit[101][101];

void bfs(int x, int y)
{
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) visit[i][j] = 0;
			else visit[i][j] = -1;
		}
	}


	return 0;
}