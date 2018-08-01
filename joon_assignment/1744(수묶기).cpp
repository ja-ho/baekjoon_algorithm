#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());
	int sum = 0;
	for (int i = 0; i < n - 1; i+=2l) {
		if (num[i] < 0 && num[i] < 0) sum = num[i] * num[i];
		else if (num[i] <)
	}

	return 0;
}