#include <iostream>
#include <algorithm>
using namespace std;

int waitTime[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> waitTime[i];
	}

	sort(waitTime, waitTime + n);
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		sum += waitTime[i];
		ans += sum;
	}
	cout << ans << '\n';
	return 0;
}
