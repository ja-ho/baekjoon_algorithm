#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		int k;
		vector<int> v;
		vector<int> ball;
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		for (int i = 0; i < k - 6; i++) {
			ball.push_back(1);
		}
		for (int i = 0; i < 6; i++) {
			ball.push_back(0);
		}
		sort(ball.begin(), ball.end());
		do {
			for (int i = 0; i < k; i++) {
				if (ball[i] == 0) {
					cout << v[i] << " ";
				}
			}
			cout << '\n';
		} while (next_permutation(ball.begin(), ball.end()));
		cout << '\n';
	}
	return 0;
}