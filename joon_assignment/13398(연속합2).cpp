#include <iostream>
using namespace std;

int a[100001];
int dl[100001];
int dr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dl[1] = a[1];
	dr[n] = a[n];
	for (int i = 2; i <= n; i++) {
		dl[i] = a[i];
		if (dl[i] < dl[i - 1] + a[i]) {
			dl[i] = dl[i - 1] + a[i];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		dr[i] = a[i];
		if (dr[i] < dr[i + 1] + a[i]) {
			dr[i] = dr[i + 1] + a[i];
		}
	}

	int answer = -9999999;
	for (int i = 2; i < n; i++) {
		if (answer < dl[i - 1] + dr[i + 1]) {
			answer = dl[i - 1] + dr[i + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (answer < dl[i]) answer = dl[i];
	}
	cout << answer << '\n';
	return 0;
}