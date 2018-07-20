#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int map[11][11];
int n;

int main() {
	vector<int> v;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}

	int ans = 999999999;
	do {
		bool can_go = true;
		int tmp_sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (map[v[i]][v[i + 1]] == 0) {
				can_go = false;
				break;
			}
			else tmp_sum += map[v[i]][v[i + 1]];
		}
		if (can_go && map[v[n - 1]][v[0]]) {
			if (ans > tmp_sum + map[v[n - 1]][v[0]])
				ans = tmp_sum + map[v[n - 1]][v[0]];
		}
	} while (next_permutation(v.begin() + 1, v.end()));

	cout << ans << '\n';
	return 0;
}