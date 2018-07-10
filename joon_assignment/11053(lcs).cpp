#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sequence[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int answer;
	cin >> n;
	vector<int> v;

	for (int i = 1; i <= n; i++) {
		cin >> sequence[i];
	}

	v.push_back(sequence[1]);
	answer = 1;
	for (int i = 2; i <= n; i++) {
		if (v.back() < sequence[i]) {
			v.push_back(sequence[i]);
			answer++;
		}
		else {
			vector<int>::iterator lower = lower_bound(v.begin(), v.end(), sequence[i]);
			*lower = sequence[i];
		}
	}
	cout << answer << '\n';
	return 0;
}