#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int sum = 0;
		if (a != 0 && a < 22) {
			if (a == 1) sum += 5000000;
			else if (a < 4) sum += 3000000;
			else if (a < 7) sum += 2000000;
			else if (a < 11) sum += 500000;
			else if (a < 16) sum += 300000;
			else if (a < 22) sum += 100000;
		}
		if (b != 0 && b < 32) {
			if (b == 1) sum += 5120000;
			else if (b < 4) sum += 2560000;
			else if (b < 8) sum += 1280000;
			else if (b < 16) sum += 640000;
			else if (b < 32) sum += 320000;
		}
		cout << sum << '\n';
	}
	return 0;
}