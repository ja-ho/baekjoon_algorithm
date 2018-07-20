#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, s;
	vector<int> v;
	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += v[j];
			}
		}
		if (sum == s) 
			ans++;
	}
	cout << ans << '\n';
	return 0;
}