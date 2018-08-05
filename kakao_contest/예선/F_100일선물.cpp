#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> point(n);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		point[i] = make_pair(x, y);
	}

	if (n == 4) {
		cout << point[2].first * point[2].second << '\n';
	}
	else {
		
	}

	return 0;
}