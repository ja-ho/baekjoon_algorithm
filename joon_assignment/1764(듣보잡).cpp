#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	unordered_map<string, int> hash_map;
	cin >> n >> m;
	string temp;
	while (n--) {
		cin >> temp;
		hash_map[temp] |= 1;
	}

	while (m--) {
		cin >> temp;
		hash_map[temp] |= 2;
	}

	unordered_map<string, int>::iterator it;
	vector<string> ans;
	for (it = hash_map.begin(); it != hash_map.end(); it++) {
		if (it->second == 3) {
			ans.push_back(it->first);
		}
	}

	int ans_length = ans.size();
	cout << ans_length << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans_length; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}