#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
char a[100001];
char b[100001];
char temp[100001];

void flip(int i)
{
	if (i == 0 || i == n - 1) {
		if (i == 0) {
			temp[0] = (temp[0] == '1' ? '0' : '1');
			temp[1] = (temp[1] == '1' ? '0' : '1');
		}
		else if (i == n - 1) {
			temp[n - 1] = (temp[n - 1] == '1' ? '0' : '1');
			temp[n - 2] = (temp[n - 2] == '1' ? '0' : '1');
		}
	}
	else {
		temp[i - 1] = (temp[i - 1] == '1' ? '0' : '1');
		temp[i] = (temp[i] == '1' ? '0' : '1');
		temp[i + 1] = (temp[i + 1] == '1' ? '0' : '1');
	}
	return;
}

pair<bool, int> go()
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
		temp[i] = a[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (temp[i] != b[i]) {
			flip(i + 1);
			ans++;
		}
	}
	bool same = true;
	for (int i = 0; i < n; i++) {
		if (temp[i] != b[i]) {
			same = false;
			break;
		}
	}
	if (same) {		//need check
		return (make_pair(true, ans));
	}
	else {
		return (make_pair(false, ans));
	}
}


int main() {
	

	cin >> n;
	cin >> a;
	cin >> b;
	
	int cnt = 0;
	auto p1 = go();
	a[0] = (a[0] == '1' ? '0' : '1');
	a[1] = (a[1] == '1' ? '0' : '1');
	auto p2 = go();
	p2.second++;
	if (p1.first && p2.first) {
		if (p1.second > p2.second) cout << p2.second << '\n';
		else cout << p1.second << '\n';
	}
	else if (p1.first) cout << p1.second << '\n';
	else if (p2.first) cout << p2.second << '\n';
	else cout << -1 << '\n';

	return 0;
}