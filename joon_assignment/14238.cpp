#include <iostream>
#include <string>
using namespace std;

string s;
int s_length;
int a_num, b_num, c_num;	//a == 0, b == 1, c == 2
char ans[52];
int d[52][52][52][3][3];

bool go(int a, int b, int c, int last_one, int last)
{
	if (a + b + c == s_length) {
		if (last == 0) return true;
		if (last_one == last) return false;
		return true;
	}

	if (d[a][b][c][last_one][last]) return false;
	d[a][b][c][last_one][last] = true;

	if (a_num > a) {
		ans[a + b + c] = 'A';
		if (go(a + 1, b, c, last, 0)) return true;
	}

	if (last != 1 && b_num > b) {
		ans[a + b + c] = 'B';
		if (go(a, b + 1, c, last, 1)) return true;
	}
	
	if (last_one != 2 && last != 2 && c_num > c) {
		ans[a + b + c] = 'C';
		if (go(a, b, c + 1, last, 2)) return true;
	}	
	return false;
}

int main() {
	cin >> s;
	s_length = s.size();
	for (int i = 0; i < s_length; i++) {
		if (s[i] == 'A') a_num++;
		else if (s[i] == 'B') b_num++;
		else c_num++;
	}

	if (go(0, 0, 0, -1, -1)) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}