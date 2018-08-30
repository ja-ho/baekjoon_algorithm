#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	map<int, long long> mp;
	cin >> n >> k;
	int ans = 0;
	int sum = 0;
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		sum += num;
		ans += mp[sum - k];
		mp[sum]++;
	}
	cout << ans << '\n';
	return 0;
}