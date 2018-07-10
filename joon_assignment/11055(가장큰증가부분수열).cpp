#include <iostream>
using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))
int a[1001];
int d[1001];

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
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] > a[j]) {
				d[i] = max(d[i], d[j] + a[i]);
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, d[i]);
	}
	cout << answer << '\n';
	return 0;
}