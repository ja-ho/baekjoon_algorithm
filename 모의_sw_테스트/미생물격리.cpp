#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class group {
public:
	int x, y;
	int num;
	int dir;
	group():x(0), y(0), num(0), dir(0) {

	};
	group(int x, int y, int num, int dir) : x(x), y(y), num(num), dir(dir) {

	};
};

bool move(int n, int id, group &bugs, vector<group> &groups, map<pair<int, int>, vector<int>> &map)	//1 == 상, 2 == 하, 3 == 좌, 4 == 우
{
	int x = bugs.x;
	int y = bugs.y;
	bool flag = false;
	if (bugs.dir == 1) {
		x -= 1;
		if (x == 0) {
			flag = true;
		}
	}
	else if (bugs.dir == 2) {
		x += 1;
		if (x == n - 1) {
			flag = true;
		}
	}
	else if (bugs.dir == 3) {
		y -= 1;
		if (y == 0) {
			flag = true;
		}
	}
	else {
		y += 1;
		if (y == n - 1) {
			flag = true;
		}
	}
	if (flag) {
		bugs.num /= 2;
		if (bugs.dir == 1) bugs.dir = 2;
		else if (bugs.dir == 2) bugs.dir = 1;
		else if (bugs.dir == 3) bugs.dir = 4;
		else bugs.dir = 3;
	}
	bugs.x = x;
	bugs.y = y;
	if (bugs.num == 0) {
		groups.erase(groups.begin() + id);
		return true;
	}
	map[make_pair(bugs.x, bugs.y)].push_back(id);
	return false;
}

int main() {
	freopen("C:\\Users\\magic\\jaeho\\Project1\\Project1\\baekjoon_algorithm\\모의_sw_테스트\\input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ans = 0;
		int n, m, k;
		cin >> n >> m >> k;

		vector<group> groups;
		for (int i = 0; i < k; i++) {
			int x, y, num, dir;
			cin >> x >> y >> num >> dir;
			groups.push_back(group(x, y, num, dir));
		}

		while (m--) {
			map<pair<int, int>, vector<int>> map;

			int group_size = groups.size();
			int remove_num = 0;
			for (int i = 0; i < group_size; i++) {
				if (move(n, i, groups[i], groups, map)) {
					remove_num++;
					i--;
					group_size--;
				}
			}
			group_size -= remove_num;
			for (int i = 0; i < group_size; i++) {
				if (map[make_pair(groups[i].x, groups[i].y)].size() > 1) {
					int max = 0;
					int max_dir = 0;
					int group_sum = 0;
					for (int j = 0; j < map[make_pair(groups[i].x, groups[i].y)].size(); j++) {
						group_sum += groups[map[make_pair(groups[i].x, groups[i].y)][j]].num;
						if (max < groups[map[make_pair(groups[i].x, groups[i].y)][j]].num) {
							max = groups[map[make_pair(groups[i].x, groups[i].y)][j]].num;
							max_dir = groups[map[make_pair(groups[i].x, groups[i].y)][j]].dir;
						}
					}
					map[make_pair(groups[i].x, groups[i].y)].clear();
					group new_group = group(groups[i].x, groups[i].y, group_sum, max_dir);
					groups.push_back(new_group);
					
				}
			}
			for (int i = group_size - 1; i >= 0; i--) {
				if (map[make_pair(groups[i].x, groups[i].y)].size() == 0) {
					groups.erase(groups.begin() + i);
				}
			}
		}
		int group_size = groups.size();
		for (int i = 0; i < group_size; i++) {
			ans += groups[i].num;
		}
		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;
}



//////
//다른 사람 코드
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//struct Node {
//	int x;
//	int y;
//	int num;
//	int dir;
//};
//
//int t, n, m, k;
//int dx[] = { 0,-1,1,0,0 };
//int dy[] = { 0,0,0,-1,1 };
//vector<int> map[100][100];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//
//	cin >> t;
//
//	for (int tc = 1; tc <= t; tc++) {
//		cin >> n >> m >> k;
//
//		vector<Node> v(k);
//		for (int i = 0; i < k; i++) {
//			cin >> v[i].x >> v[i].y >> v[i].num >> v[i].dir;
//			v[i].dir;
//			map[v[i].x][v[i].y].push_back(i);
//		}
//
//		while (m--) {
//
//			// 군집 삭제
//			for (int i = 0; i < k; i++) {
//				if (v[i].num == 0) continue;
//				map[v[i].x][v[i].y].clear();
//			}
//
//			// 군집 이동
//			for (int i = 0; i < k; i++) {
//				if (v[i].num == 0) continue;
//				v[i].x += dx[v[i].dir];
//				v[i].y += dy[v[i].dir];
//				map[v[i].x][v[i].y].push_back(i);
//			}
//
//			for (int i = 0; i < k; i++) {
//				if (v[i].num == 0) continue;
//
//				//가장자리에 닿은 경우
//				if (v[i].x == 0 || v[i].y == 0 || v[i].x == n - 1 || v[i].y == n - 1) {
//					v[i].num = v[i].num / 2; //미생물 1/2감소
//					//방향전환
//					if (v[i].dir == 1) v[i].dir = 2;
//					else if (v[i].dir == 2) v[i].dir = 1;
//					else if (v[i].dir == 3)v[i].dir = 4;
//					else v[i].dir = 3;
//				}
//				//여러 군집이 뭉친 경우
//				else if (map[v[i].x][v[i].y].size() > 1) {
//					int x = v[i].x;
//					int y = v[i].y;
//					int max_num = 0;
//					int max_cnt = 0;
//					int max_dir = 0;
//					int sum = 0;
//					for (int i = 0; i < map[x][y].size(); i++) {
//						sum += v[map[x][y][i]].num; // 미생물 수 합
//						// 최대 미생물을 가진 군집 찾기
//						if (max_num < v[map[x][y][i]].num) {
//							max_num = v[map[x][y][i]].num;
//							max_dir = v[map[x][y][i]].dir;
//							max_cnt = map[x][y][i];
//						}
//						v[map[x][y][i]].num = 0;
//					}
//					v[max_cnt].num = sum;
//					v[max_cnt].dir = max_dir;
//				}
//			}
//		}
//
//		//남은 미생물 계산
//		int res = 0;
//		for (int i = 0; i < k; i++) {
//			res += v[i].num;
//		}
//
//		//맵초기화
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				map[i][j].clear();
//			}
//		}
//
//		cout << "#" << tc << " " << res << "\n";
//	}
//}