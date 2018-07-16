#include <iostream>
#include <vector>
using namespace std;

int visit[20001];
vector<vector<int>> v;

bool dfs(int i, int c) 
{
	visit[i] = c;

	int v_i_length = v[i].size();
	for (int j = 0; j < v_i_length; j++) {
		int next = v[i][j];
		if (visit[next] == visit[i]) return false;
		else if (visit[next] == 0) {
			if (dfs(next, 3 - c) == false) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int V, E;
		cin >> V >> E;
		v.clear();
		v.resize(V + 1);
		for (int x = 0; x <= V; x++) {
			visit[x] = 0;
		}
		for (int j = 0; j < E; j++) {
			int t1, t2;
			cin >> t1 >> t2;
			v[t1].push_back(t2); v[t2].push_back(t1);
		}
		bool ok = true;
		int v_length = v.size();
		for (int j = 1; j < v_length; j++) {
			if (visit[j] == 0) {
				if (dfs(j, 1) == false) {
					ok = false;
				}
			}
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}