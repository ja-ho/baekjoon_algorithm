#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[1001];
vector<vector<int>> v;

void dfs(int i)
{
	visit[i] = true;

	int v_size = v[i].size();
	for (int j = 0; j < v_size; j++) {
		int next = v[i][j];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2); v[t2].push_back(t1);
	}

	int v_length = v.size();
	int answer = 0;
	for (int i = 1; i < v_length; i++) {
		if (!visit[i]) {
			dfs(i);
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}