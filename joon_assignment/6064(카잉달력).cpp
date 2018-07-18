#include <iostream>
using namespace std;

//int gcd(int a, int b)
//{
//	if (b == 0) return a;
//	else return gcd(b, a%b);
//}
//
//int find_lcm(int x, int y)
//{
//	int gcd_num = gcd(x, y);
//	int lcm_num = x * y / gcd_num;
//	return lcm_num;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int M, N, X, Y;
		cin >> M >> N >> X >> Y;
		//int lcm_num = find_lcm(m, n);
		bool find = false;
		int x, y, i;
		for (i = 0; i < N; i++) {
			y = (M * i + X) % N;
			if (y == 0) y = N;
			if (y == Y) {
				find = true;
				break;
			}
		}
		if (!find) cout << -1 << '\n';
		else cout << i * M + X << '\n';

	}
	return 0;
}