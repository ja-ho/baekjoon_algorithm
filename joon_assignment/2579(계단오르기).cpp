#include <iostream>
using namespace std;
#define max(a, b)	(((a) > (b)) ? (a) : (b))

int stairs[301];
int d[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}
	d[1] = stairs[1];
	d[2] = stairs[1] + stairs[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 3] + stairs[i - 1], d[i - 2]) + stairs[i];
	}

	cout << d[n] << '\n';
	return 0;
}