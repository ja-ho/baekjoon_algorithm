//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//int ans;
//int n, k;
//
//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0 , 1, 0, -1 };
//
//bool visit[8][8];
//
//void go(int x, int y, int cnt, vector<vector<int>>& map)
//{
//	if (visit[x][y]) return;
//	if (cnt > ans) ans = cnt;
//	visit[x][y] = true;
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//		if (map[nx][ny] >= map[x][y]) continue;
//		else {
//			go(nx, ny, cnt + 1, map);
//		}
//	}
//	visit[x][y] = false;
//	return;
//}
//
//int main() {
//	freopen("C:\\Users\\magic\\jaeho\\Project1\\Project1\\baekjoon_algorithm\\모의_sw_테스트\\input.txt", "r", stdin);
//	int t;
//	cin >> t;
//	int tn = 1;
//	while (t--) {
//		ans = 0;
//		cin >> n >> k;
//		vector<vector<int>> map(n);
//		for (int i = 0; i < n; i++) {
//			map[i].resize(n);
//		}
//		vector<pair<int, int>> highest;
//		int max = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> map[i][j];
//				if (map[i][j] > max) {
//					max = map[i][j];
//				}
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (map[i][j] == max) highest.push_back(make_pair(i, j));
//			}
//		}
//
//		for (int c = 0; c < highest.size(); c++) {
//			int x = highest[c].first;
//			int y = highest[c].second;
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					visit[i][j] = false;
//				}
//			}
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					if (i == x && j == y) continue;
//					for (int m = 1; m <= k; m++) {
//						map[i][j] -= m;
//						go(x, y, 1, map);
//						map[i][j] += m;
//					}
//					//map[i][j] -= 1;
//					//go(x, y, 1, map);
//					//map[i][j] += 1;
//
//				}
//			}
//		}
//		cout << "#" << tn << ' ' << ans << '\n';
//		tn++;
//	}
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int ans;
int n, k;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0 , 1, 0, -1 };

bool visit[8][8];

void go(int x, int y, int cnt, bool used, vector<vector<int>>& map)
{
	if (visit[x][y]) return;
	if (cnt > ans) ans = cnt;
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (visit[nx][ny]) continue;
		if (map[nx][ny] >= map[x][y]) {
			if (used) continue;
			else {
				if (map[x][y] > map[nx][ny] - k) {
					int temp = map[nx][ny];
					map[nx][ny] = map[x][y] - 1;
					go(nx, ny, cnt + 1, true, map);
					map[nx][ny] = temp;
				}
			}
		}
		else {
			go(nx, ny, cnt + 1, used, map);
		}
	}
	visit[x][y] = false;
	return;
}

int main() {
	//freopen("C:\\Users\\magic\\jaeho\\Project1\\Project1\\baekjoon_algorithm\\모의_sw_테스트\\input.txt", "r", stdin);
	int t;
	cin >> t;
	int tn = 1;
	while (t--) {
		ans = 0;
		cin >> n >> k;
		vector<vector<int>> map(n);
		for (int i = 0; i < n; i++) {
			map[i].resize(n);
		}
		vector<pair<int, int>> highest;
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] > max) {
					max = map[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == max) highest.push_back(make_pair(i, j));
			}
		}

		for (int c = 0; c < highest.size(); c++) {
			int x = highest[c].first;
			int y = highest[c].second;
			go(x, y, 1, false, map);

		}
		cout << "#" << tn << ' ' << ans << '\n';
		tn++;
	}
	return 0;
}