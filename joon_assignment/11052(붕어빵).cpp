#include <iostream>
#include <algorithm>
using namespace std;


int d[1001];
int price[1001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}
	d[1] = price[1];
	for (int i = 2; i <= N; i++) {
		d[i] = price[i];
		for (int j = i - 1; j >= 1; j--) {
			d[i] = max(d[i], d[j] + price[i - j]);
		}
	}
	cout << d[N] << '\n';
	return 0;
}