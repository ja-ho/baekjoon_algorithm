#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;


int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool answer;
bool visit[17][17];
int map[17][17];


void dfs(int x, int y) {
	if (x == 11 && y == 11) {
		answer = true;
		return;
	}

	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;
		if (map[ny][nx] == 1) continue;
		if (visit[ny][nx] == true) continue;
		dfs(nx, ny);
	}
	return;
}



int main() {

	freopen("input.txt", "r", stdin);
	int T;
	for (int tc = 1; tc <= 10; tc++) {
		answer = false;
		
		cin >> T;
		
		for (int i = 0; i < 16; i++) {
			string temp;
			temp.resize(17);
			cin >> temp;
			for (int j = 0; j < 16; j++) {
				map[i][j] = temp[j] - 48;
				visit[i][j] = false;
			}
		}
		dfs(1, 1);

		cout << "#" << T << " " << answer << endl;
	}
	return 0;
}