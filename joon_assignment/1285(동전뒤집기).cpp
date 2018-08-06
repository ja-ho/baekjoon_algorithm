#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;

char flip(char x)
{
	if (x == 'H') return 'T';
	else return 'H';
}

int main() {
	cin >> n;
	vector<string> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	int sum;
	int ans = n*n;
	for (int state = 0; state < (1 << n); state++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (state & (1 << i)) {
					if (flip(coins[i][j]) == 'T') cnt++;
				}
				else if (coins[i][j] == 'T') cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		if (ans > sum) ans = sum;
	}
	cout << ans << '\n';
	return 0;
}