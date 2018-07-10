#include <iostream>
using namespace std;

int a[100001];
int d[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i] = a[i];
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	int answer = -9999;
	for (int i = 1; i <= n; i++) {
		if (answer < d[i]) answer = d[i];
	}

	cout << answer << '\n';

	return 0;
}