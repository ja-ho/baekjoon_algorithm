#include <iostream>
using namespace std;
#define max(a, b)	(((a) > (b)) ? (a) : (b))

int wine[10001];
int d[10001];
//int d[10001][2];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> wine[i];
//	}
//
//	d[1][0] = 0;
//	d[1][1] = wine[1];
//	d[2][0] = wine[1];
//	d[2][1] = d[1][1] + wine[2];
//	for (int i = 3; i <= n; i++) {
//		d[i][0] = max(d[i - 1][0], d[i - 1][1]);
//		d[i][1] = max(d[i - 2][1], d[i - 2][0] + wine[i - 1]) + wine[i];
//	}
//
//	int answer = max(d[n][0], d[n][1]);
//	cout << answer << '\n';
//	return 0;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
	}
	
	d[1] = wine[1];
	d[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1];
		d[i] = max(max(d[i], d[i - 2] + wine[i]), d[i - 3] + wine[i - 1] + wine[i]);
	}
	cout << d[n] << '\n';
	return 0;
}