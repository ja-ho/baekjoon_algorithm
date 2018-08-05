#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

char a[51][51];
char b[51][51];

void flip(int x, int y)
{
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			a[i][j] = (a[i][j] == '1' ? '0' : '1');
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				flip(i, j);
				ans++;
			}
		}
	}
	bool same = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				same = false;
				break;
			}
		}
		if (!same) break;
	}
	if (same) cout << ans << '\n';
	else cout << -1 << '\n';
	return 0;
}