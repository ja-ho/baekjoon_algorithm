#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, int>> time;	//end, start

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int e, s;
		cin >> s >> e;
		time.push_back(make_pair(e, s));
	}

	sort(time.begin(), time.end());

	int ans = 0;
	int temp_end = 0;
	for (int i = 0; i < n; i++) {
		if (time[i].second >= temp_end) {
			temp_end = time[i].first;
			ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}