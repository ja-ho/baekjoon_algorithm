#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int n;

int map[22][22];
int temp_map[22][22];
bool fusion[22][22];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool change;
int answer;

void moving(int x, int y, int dir) {
	if (dir == 0) {			//북으로
		while (true) {
			if (y > 0) {
				if (temp_map[y - 1][x] == 0) {
					temp_map[y - 1][x] = temp_map[y][x];
					temp_map[y][x] = 0;
					y--;
					change = true;
				}
				else if (temp_map[y - 1][x] == temp_map[y][x] && !fusion[y - 1][x]) {
					temp_map[y - 1][x] *= 2;
					temp_map[y][x] = 0;
					fusion[y - 1][x] = true;
					change = true;
					return;
				}
				else {
					return;
				}
			}
			else {
				return;
			}
		}
	}
	else if (dir == 1) {	//동으로
		while (true) {
			if (x < n - 1) {
				if (temp_map[y][x + 1] == 0) {
					temp_map[y][x + 1] = temp_map[y][x];
					temp_map[y][x] = 0;
					x++;
					change = true;
				}
				else if (temp_map[y][x + 1] == temp_map[y][x] && !fusion[y][x + 1]) {
					temp_map[y][x + 1] *= 2;
					temp_map[y][x] = 0;
					fusion[y][x + 1] = true;
					change = true;
					return;
				}
				else {
					return;
				}
			}
			else {
				return;
			}
		}
	}
	else if (dir == 2) {	//남으로
		while (true) {
			if (y < n - 1) {
				if (temp_map[y + 1][x] == 0) {
					temp_map[y + 1][x] = temp_map[y][x];
					temp_map[y][x] = 0;
					y++;
					change = true;
				}
				else if (temp_map[y + 1][x] == temp_map[y][x] && !fusion[y + 1][x]) {
					temp_map[y + 1][x] *= 2;
					temp_map[y][x] = 0;
					fusion[y + 1][x] = true;
					change = true;
					return;
				}
				else {
					return;
				}
			}
			else {
				return;
			}
		}
	}
	else {					//서로
		while (true) {
			if (x > 0) {
				if (temp_map[y][x - 1] == 0) {
					temp_map[y][x - 1] = temp_map[y][x];
					temp_map[y][x] = 0;
					change = true;
					x--;
				}
				else if (temp_map[y][x - 1] == temp_map[y][x] && !fusion[y][x - 1]) {
					temp_map[y][x - 1] *= 2;
					temp_map[y][x] = 0;
					fusion[y][x - 1] = true;
					change = true;
					return;
				}
				else {
					return;
				}
			}
			else {
				return;
			}
		}
	}
}

//dir == 0 north, dir == 1 east, dir == 2 south, dir == 3 west
void move_command(int dir)
{
	if (dir == 0) {			//북으로
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (temp_map[i][j]) {
					moving(j, i, dir);
				}
			}
		}
	}
	else if (dir == 1) {	//동으로
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (temp_map[i][j]) {
					moving(j, i, dir);
				}
			}
		}
	}
	else if (dir == 2) {	//남으로
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (temp_map[i][j]) {
					moving(j, i, dir);
				}
			}
		}
	}
	else {					//서로
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (temp_map[i][j]) {
					moving(j, i, dir);
				}
			}
		}
	}
	return;
}

void dfs(int cnt, int dfs_map[22][22])
{
	int t_map[22][22];

	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (answer < dfs_map[i][j]) {
					answer = dfs_map[i][j];
					return;
				}
			}
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp_map[i][j] = dfs_map[i][j];
				fusion[i][j] = false;
			}
		}
		change = false;
		move_command(dir);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				t_map[i][j] = temp_map[i][j];
			}
		}
		dfs(cnt + 1, t_map);
	}
	return;
}

int main() {
	scanf("%d", &n);
	vector<pair<pair<int, int>, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}	
	if (n == 1) {
		answer = map[0][0];
	}
	else {
		dfs(0, map);
	}
	printf("%d\n", answer);
	return 0;
}