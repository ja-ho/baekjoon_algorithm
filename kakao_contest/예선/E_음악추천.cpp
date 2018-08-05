#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

int score[100001];
int songs[100001];
int singers[100001];
int tree[100001];
int total[10001];
set<int> key[100001];
int result[100001];
unordered_map<int, int> trees[100001];
int n, k, j;

void cnt_singer(int parent, int singer)
{
	if (tree[parent] != 0) {
		cnt_singer(tree[parent], singer);
	}
	if (!trees[parent].insert(pair<int,int>(singer, 1)).second) {
		trees[parent][singer]++;
	}
	key[parent].insert(singer);
	total[parent]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> j;
	for (int i = 2; i <= n; i++) {
		int parent;
		cin >> parent;
		tree[i] = parent;
	}

	for (int i = 1; i <= n; i++) {
		int singer;
		cin >> singer;
		singers[singer]++;
		songs[i] = singer;
		cnt_singer(i, singer);		
	}

	for (int i = 0; i < k; i++) {
		int t, s, p;
		cin >> t >> s >> p;
		set<int>::iterator iter;
		unordered_map<int, int>::iterator map_iter;
		double each_p = (double)p / (double)total[s];
		for (iter = key[s].begin(); iter != key[s].end(); iter++) {
			map_iter = trees[s].find(*iter);
			score[*iter] += each_p * map_iter->second / singers[*iter];
			if (score[*iter] > j) {

				if (result[*iter] == 0) result[*iter] = t;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (result[i])
	}

	for (int i = 1; i <= n; i++) {
		if (result[i] == 0) cout << -1 << '\n';
		else cout << result[i] << '\n';
	}
	return 0;
}