//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
//#include <queue>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n, k;
//	cin >> n >> k;
//	vector<pair<int, int>> jewels;
//	multiset<int> bags;
//
//	for (int i = 0; i < n; i++) {
//		int m, v;
//		cin >> m >> v;
//		jewels.push_back(make_pair(v, m));
//	}
//
//	for (int i = 0; i < k; i++) {
//		int m;
//		cin >> m;
//		bags.insert(m);
//	}
//
//	sort(jewels.begin(), jewels.end());
//	
//
//	int cnt = 0;
//	long long ans = 0;
//	for (int i = n - 1; i >= 0; i--) {
//		auto it = bags.lower_bound(jewels[i].second);
//		if (it != bags.end()) {
//			ans += jewels[i].first;
//			bags.erase(it);
//		}
//	}
//
//	cout << ans << '\n';
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> container(n + k);
	int i;
	for (i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		container[i] = make_pair(m, v);
	}

	for (; i < n + k; i++) {
		int m;
		cin >> m;
		container[i] = (make_pair(m, 1000000000));
	}

	sort(container.begin(), container.end());
		priority_queue<int> q;
	long long ans = 0;
	for (int j = 0; j < n + k; j++) {
		auto temp = container[j];
		if (temp.second != 1000000000) {
			q.push(temp.second);
		}
		else {
			if (!q.empty()) {
				ans += (long long)q.top();
				q.pop();
			}
		}
	}

	cout << ans << '\n';
	return 0;
}