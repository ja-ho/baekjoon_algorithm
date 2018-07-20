#include <iostream>
#include <cstdio>
using namespace std;

char map[4][4];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int ans = 0;
	for (int set_num = 0; set_num < (1 << (n*m)); set_num++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < m; j++) {
				int k = i * m + j;
				if ((set_num & (1 << k)) == 0) {
					temp = temp * 10 + (map[i][j] - 48);
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}
		for (int j = 0; j < m; j++) {
			int temp = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				if ((set_num & (1 << k)) != 0) {
					temp = temp * 10 + (map[i][j] - 48);
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}
		if (ans < sum) 
			ans = sum;
	}
	cout << ans << '\n';
	return 0;
}