#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

bool next_permutation(vector<int> &v, int n)
{
	int i = n - 1;
	while (i > 0 && v[i] <= v[i - 1]) i--;
	if (i <= 0) return false;
	int j = n - 1;
	while (j > i && v[j] <= v[i - 1]) j--;
	swap(&v[i - 1], &v[j]);
	j = n - 1;
	while (i < j) {
		swap(v[i], v[j]);
		i++; j--;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (next_permutation(v, n)) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}