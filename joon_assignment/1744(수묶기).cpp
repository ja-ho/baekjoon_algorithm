#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> plus;
	vector<int> minus;
	cin >> n;
	int one = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 1) plus.push_back(x);
		else if (x < 0) minus.push_back(x);
		else if (x == 1) one++;
		else if (x == 0) zero++;
	}

	sort(plus.begin(), plus.end());
	reverse(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	int sum = 0;
	if (plus.size() % 2 == 1) plus.push_back(1);
	for (int i = 0; i < plus.size(); i += 2) {
		sum += plus[i] * plus[i + 1];
	}
	sum += one;

	if (minus.size() % 2 == 1) {
		if (zero == 0) minus.push_back(1);
		else {
			minus.push_back(0);
			zero -= 1;
		}
	}
	for (int i = 0; i < minus.size(); i += 2) {
		sum += minus[i] * minus[i + 1];
	}

	cout << sum << '\n';
	return 0;
}