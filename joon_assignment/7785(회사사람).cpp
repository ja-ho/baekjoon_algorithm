#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string temp1, temp2;
	unordered_map<string, int> hash_mp;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		if (temp2[0] == 'e') {
			hash_mp[temp1] |= 1;
		}
		else {
			hash_mp[temp1] &= 0;
		}
	}
	vector<string> ans;
	unordered_map<string, int>::iterator it;
	for (it = hash_mp.begin(); it != hash_mp.end(); it++) {
		if (it->second) {
			ans.push_back(it->first);
		}
	}
	sort(ans.begin(), ans.end());
	int ans_length = ans.size();
	for (int i = ans_length -1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}

	return 0;
}