#include <iostream>
using namespace std;

int d[31];

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		d[0] = 1;
		d[2] = 3;
		for (int i = 4; i <= n; i += 2) {
			d[i] = d[i - 2] * 3;
			for (int j = i-4; j >= 0; j -= 2) {
				d[i] += d[j] * 2;
			}
		}
		cout << d[n] << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}