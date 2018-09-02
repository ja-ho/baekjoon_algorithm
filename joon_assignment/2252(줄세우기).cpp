#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int in_degree[32001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> students(n + 1);
	priority_queue<int, vector<int>> pq;
	vector<int> ans;
	while (m--) {
		int a, b;
		cin >> a >> b;
		in_degree[b]++;
		students[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			pq.push(-i);
			ans.push_back(i);
		}
	}

	while (!pq.empty()) {
		int x = -pq.top();
		pq.pop();
		for (int i = 0; i < students[x].size(); i++) {
			in_degree[students[x][i]]--;
			if (in_degree[students[x][i]] == 0) {
				pq.push(-students[x][i]);
				ans.push_back(students[x][i]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}