#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int h, w;
int t;

int answer;

char map[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };


// dfs는 시간 초과
//void dfs(int x, int y, int cnt, bool second)
//{
//	if (cnt >=  answer) return;
//	if (x == 0 || x == w - 1 || y == 0 || y == h - 1) {
//		if (!second) {
//			dfs(pos[1].first, pos[1].second, cnt, true);
//		}
//		if (second && answer > cnt) {
//			answer = cnt;
//		}
//		map[y][x] = temp_map[y][x];
//		return;
//	}
// 	if (!second) {
//		visit[y][x] = true;
//	}
//	else {
//		visit_2[y][x] = true;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		int temp_cnt = cnt;
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		char origin_room = map[ny][nx];
//
//		if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
//		if (map[ny][nx] == '*') continue;
//		if (!second) {
//			if (visit[ny][nx] == true) continue;
//		}
//		else {
//			if (visit_2[ny][nx] == true) continue;
//		}
//		if (map[ny][nx] == '#') {
//			map[ny][nx] = '.';
//			temp_cnt += 1;
//		}
//
//		dfs(nx, ny, temp_cnt, second);
//		map[ny][nx] = origin_room;
//	}
//	if (!second) {
//		visit[y][x] = false;
//	}
//	else {
//		visit_2[y][x] = false;
//	}
//}


vector<vector<int> > bfs(int x, int y)
{
	vector < vector<int> > temp;
	queue <pair<int, int> > pos;
	temp.resize(h + 2);
	for (int i = 0; i <= h + 1; i++) {
		temp[i].resize(w + 2);
	}

	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			temp[i][j] = -1;
		}
	}

	pos.push(make_pair(x, y));
	temp[y][x] = 0;

	while (!pos.empty()) {
		int cx = pos.front().first;
		int cy = pos.front().second;
		pos.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx > w + 1 || ny < 0 || ny > h + 1) continue;
			if (map[ny][nx] == '*') continue;

			if (map[ny][nx] == '#') {
				if (temp[ny][nx] == -1 || temp[ny][nx] > temp[cy][cx] + 1) {
					temp[ny][nx] = temp[cy][cx] + 1;	
					pos.push(make_pair(nx, ny));
				}
			}
			else {
				if (temp[ny][nx] == -1 || temp[ny][nx] > temp[cy][cx]) {
					temp[ny][nx] = temp[cy][cx];
					pos.push(make_pair(nx, ny));
				}
			}
		}
	}	
	return temp;
}


int main() {
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++) {
		vector< pair <int, int > > start;
		answer = 99999;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				map[i][j] = '\0';
			}
		}
		scanf("%d %d", &h, &w);
		char temp[101];
		for (int i = 1; i <= h; i++) {
			scanf("%s", &temp);
			for (int j = 0; j < w; j++) {
				map[i][j + 1] = temp[j];
				if (map[i][j + 1] == '$') {
					start.push_back(make_pair(j + 1, i));
				}
			}
		}

		vector <vector<int> > d1;
		vector <vector<int> > d2;
		vector <vector<int> > d3;

		d1 = bfs(0, 0);		
		d2 = bfs(start[0].first, start[0].second);
		d3 = bfs(start[1].first, start[1].second);




		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (map[i][j] == '*') continue;
				int sum = d1[i][j] + d2[i][j] + d3[i][j];
				if (map[i][j] == '#') sum -= 2;
				if (answer > sum) answer = sum;
			}
		}

		//dfs(pos[0].first, pos[0].second, 0, false);
		printf("%d\n", answer);
	}
	return 0;
}