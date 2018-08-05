#include <iostream>
#include <vector>
#include <utility>
using namespace std;

char a[100001];
char b[100001];
int n;

void flip(int i)
{
	if (i == 0 || i == n) {
		if (i == 0) {
			a[0] = a[0] == '1' ? '0' : '1';
			a[1] = a[1] == '1' ? '0' : '1';
		}
		else if (i == n - 1) {
			a[n - 1] = a[n - 1] == '1' ? '0' : '1';
			a[n - 2] = a[n - 2] == '1' ? '0' : '1';
		}
	}
	else {
		a[i - 1] = a[i - 1] == '1' ? '0' : '1';
		a[i] = a[i] == '1' ? '0' : '1';
		a[i + 1] = a[i + 1] == '1' ? '0' : '1';
	}
	return;
}

pair<bool, int> go()
{
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != b[i]) {
			flip(i + 1);
			ans++;
		}
	}
	if (a == b) {		//need check
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
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			flip(i);
			cnt++;
		}
	}


	return 0;
}