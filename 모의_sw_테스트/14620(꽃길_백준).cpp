#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int map[11][11];
bool visit[11][11];
int n;
int ans;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<pair<int, int>> places;

int abs(int a, int b)
{
	if (a < b) return b - a;
	else return a - b;
}

bool is_ok(int x, int y)
{
	if (y - 2 >= 0 && visit[x][y - 2]) return false;
	if (y + 2 < n && visit[x][y + 2]) return false;
	if (x + 2 < n && visit[x + 2][y]) return false;
	if (x - 2 >= 0 && visit[x - 2][y]) return false;

	return true;
}

int seed(int x, int y) 
{
	int sum = map[x][y];
	for (int i = 0; i < 4; i++) {
		sum += map[x + dx[i]][y + dy[i]];
	}
	return sum;
}

void go(int level, int sum, int cnt, vector<pair<int,int>> visited)
{
	if (cnt == 3) {
		if (ans > sum) {
			ans = sum;
		}
		return;
	}
	else if (level == places.size()) return;

	int x = places[level].first;
	int y = places[level].second;

	go(level + 1, sum, cnt, visited);
	
	if (!is_ok(x, y)) return;
	for (int i = 0; i < (int)visited.size(); i++) {
		int cx = visited[i].first;
		int cy = visited[i].second;
		if (abs(cx, x) + abs(cy, y) <= 2) return;
	}

	vector<pair<int, int>> temp = visited;
	temp.push_back(make_pair(x, y));
	visit[x][y] = true;
	go(level + 1, sum + seed(x, y), cnt + 1, temp);
	visit[x][y] = false;
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			places.push_back(make_pair(i, j));
		}
	}

	int length = (int)places.size();
	ans = 10000;
	//for (int i = 0; i < length - 2; i++) {
	//	int ix = places[i].first; int iy = places[i].second;
	//	visit[ix][iy] = true;
	//	int iseed = seed(ix, iy);
	//	for (int j = i + 1; j < length - 1; j++) {
	//		int jx = places[j].first; int jy = places[j].second;
	//		if (abs(jx, ix) + abs(jy, iy) <= 2) continue;
	//		if (!is_ok(jx, jy)) continue;
	//		visit[jx][jy] = true;
	//		int jseed = seed(jx, jy);
	//		for (int k = j + 1; k < length; k++) {
	//			int kx = places[k].first; int ky = places[k].second;
	//			if (abs(jx, kx) + abs(jy, ky) <= 2) continue;
	//			if (abs(ix, kx) + abs(iy, ky) <= 2) continue;
	//			if (!is_ok(kx, ky)) continue;
	//			int sum = iseed + jseed + seed(kx, ky);
	//			if (sum < ans) ans = sum;
	//		}
	//		visit[jx][jy] = false;

	//	}
	//	visit[ix][iy] = false;
	//}
	vector<pair<int, int>>temp;
	go(0, 0, 0, temp);

	cout << ans << '\n';
	return 0;
}