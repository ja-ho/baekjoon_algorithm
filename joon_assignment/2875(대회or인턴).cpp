#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	int team_cnt = 0;

	while (m > 0 && n > 1 && m + n >= k + 3) {
		m -= 1;
		n -= 2;
		team_cnt++;
	}
	cout << team_cnt << '\n';
	return 0;
}