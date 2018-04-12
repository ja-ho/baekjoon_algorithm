#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int lab[11][11];
int copyLab[11][11];
int m, n;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//너무 느리다...stack 써서 그런가?? 비교횟수는 stack 사용이 1/4지만 속도에서 확연하게 차이남.
//void dfs(int x, int y) {
//	stack<pair<int, int>> st;
//	st.push(make_pair(x, y));
//	while (!st.empty()) {
//		cnt++;
//		int current_x = st.top().first;
//		int current_y = st.top().second;
//		st.pop();
//		for (int i = 0; i < 4; i++) {
//			int next_x = current_x + dx[i];
//			int next_y = current_y + dy[i];
//			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
//			if (copyLab[next_x][next_y] == 0) {
//				st.push(make_pair(next_x, next_y));
//				copyLab[next_x][next_y] = 2;
//			}
//		}
//	}
//}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
		if (copyLab[next_x][next_y] == 0) {
			copyLab[next_x][next_y] = 2;
			dfs(next_x, next_y);
		}
	}
}

int main() {
	cin >> n >> m;
	vector<pair<int, int>> v;
	vector<pair<int, int>> virus;
	int maxCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 0) {	//기둥 세울 수 있는 곳 vector에 저장
				v.push_back(make_pair(i, j));
			}
			else if (lab[i][j] == 2) {	//바이러스 있는 곳 vector에 저장
				virus.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < v.size() - 2; i++) {
		for (int j = i + 1; j < v.size() - 1; j++) {
			for (int k = j + 1; k < v.size(); k++) {
				pair<int, int>wall_1 = v[i];
				pair<int, int>wall_2 = v[j];
				pair<int, int>wall_3 = v[k];

				for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						copyLab[x][y] = lab[x][y];
					}
				}
				
				//기둥 세 개 세우기
				copyLab[wall_1.first][wall_1.second] = 1;
				copyLab[wall_2.first][wall_2.second] = 1;
				copyLab[wall_3.first][wall_3.second] = 1;

				for (int z = 0; z < virus.size(); z++) {
					int virus_x = virus[z].first;
					int virus_y = virus[z].second;
					dfs(virus_x, virus_y);
				}
								
				int count = 0;
				for (int x = 0; x < n; x++) {
					for (int y = 0; y < m; y++) {
						if (copyLab[x][y] == 0) {
							count++;
						}
					}
				}

				maxCount = MAX(maxCount, count);
			}
		}
	}

	cout << maxCount << endl;
	

	return 0;
}