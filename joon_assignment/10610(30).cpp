#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string n;
	cin >> n;

	int n_length = n.length();
	int sum = 0;
	for (int i = 0; i < n_length; i++) {
		sum += n[i] - '0';
	}
	sort(n.begin(), n.end());
	if (n[0] == '0' && sum % 3 == 0) {
		reverse(n.begin(), n.end());
		cout << n << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}