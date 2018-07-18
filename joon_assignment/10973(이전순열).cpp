#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//bool prev_permutation(vector<int> &v, int n)
//{
//	int i = n - 1;
//	while (i > 0 && v[i - 1] <= v[i]) i--;
//	if (i == 0) return false;
//	int j = n - 1;
//	while (v[j] >= v[i - 1]) j--;
//	swap(v[j], v[i - 1]);
//	j = n - 1;
//	while (i < j) {
//		swap(v[i], v[j]);
//		i++;
//		j--;
//	}
//	return true;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//if (prev_permutation(v, n)) {
	//	for (int i = 0; i < n; i++) {
	//		cout << v[i] << " ";
	//	}
	//}
	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
	}
	else {
		cout << -1;
	}
	cout << '\n';
	return 0;
}