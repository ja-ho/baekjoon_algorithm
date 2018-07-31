#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100001];

int depth[100001];
int parent[100001];
bool check[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	queue<int> q;
	parent[1] = 0;
	depth[1] = 0;
	check[1] = true;
	q.push(1);
	while (!q.empty()) {
		int x = q.front(); 
		q.pop();
		for (int y : tree[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}