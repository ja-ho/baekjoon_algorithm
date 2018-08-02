#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int a[11];
int s[11][11];
int n;
string str;

bool check(int index)
{
	int sum = 0;
	for (int i = index; i >= 0; i--) {
		sum += a[i];
		if (s[i][index] == 0) {
			if (sum != 0) return false;
		}
		else if (s[i][index] < 0) {
			if (sum >= 0) return false;
		}
		else if (s[i][index] > 0) {
			if (sum <= 0) return false;
		}
	}
	return true;	
}

 
bool go(int index)
{
	if (index == n) return true;
	if (s[index][index] == 0) {
		a[index] = 0;
		return (check(index) && go(index + 1));
	}
	for (int i = 1; i <= 10; i++) {
		a[index] = s[index][index] * i;
		if (check(index) && go(index + 1)) return true;
	}
	return false;
}


int main() {
	cin >> n;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (str[cnt] == '0') {
				s[i][j] = 0;
			} 
			else if (str[cnt] == '+') {
				s[i][j] = 1;
			}
			else if (str[cnt] == '-') {
				s[i][j] = -1;
			}
			cnt++;
		}
	}
	go(0);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}