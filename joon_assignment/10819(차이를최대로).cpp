#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int abs(int a, int b)
{
	if (a > b) return a - b;
	else return b - a;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int answer = 0;
	sort(v.begin(), v.end());
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i], v[i + 1]);
		}
		if (answer < sum) answer = sum;
	}while (next_permutation(v.begin(), v.end()));

	cout << answer << '\n';
	return 0;
}