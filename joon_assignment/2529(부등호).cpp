#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool calc_sign(vector<char> &sign, vector<int> &v)
{
	int k = sign.size();
	for (int i = 0; i < k; i++) {
		if (sign[i] == '>') {
			if (v[i] <= v[i + 1]) return false;
		}
		else if (sign[i] == '<') {
			if (v[i] > v[i + 1]) return false;
		}
	}
	return true;	
}

int main() {
	int k;
	cin >> k;
	vector<char> sign(k);
	for (int i = 0; i < k; i++) {
		cin >> sign[i];
	}
	vector<int> max_v;
	for (int i = 9; i >= 9 - k; i--) {
		max_v.push_back(i);
	}
	do {
		if (calc_sign(sign, max_v)) {
			break;
		}
	} while (prev_permutation(max_v.begin(), max_v.end()));

	vector<int> min_v;
	for (int i = 0; i <= k; i++) {
		min_v.push_back(i);
	}
	do {
		if (calc_sign(sign, min_v)) {
			break;
		}
	} while (next_permutation(min_v.begin(), min_v.end()));
	for (int i = 0; i <= k; i++) {
		cout << max_v[i];
	}
	cout << '\n';
	for (int i = 0; i <= k; i++) {
		cout << min_v[i];
	}
	cout << '\n';
	return 0;
}