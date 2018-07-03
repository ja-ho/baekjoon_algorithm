#include <iostream>
#include <string>
using namespace std;

int palindrome[10001];
int cnt;

bool is_palindrome(int n) 
{
	char num_str[6];
	int digit = 1;
	int temp = n;
	while (temp / 10 != 0) {
		temp /= 10;
		digit++;
	}
	temp = n;
	for (int i = 0; i < digit; i++) {
		num_str[i] = temp % 10;
		temp /= 10;
	}

	for (int i = 0; i < digit; i++) {
		if (num_str[i] != num_str[digit - i - 1]) return false;
	}
	return true;
}

bool one(int n)
{
	for (int i = 0; i < cnt; i++) {
		if (n == palindrome[i]) {
			cout << 1 << ' ' << palindrome[i] << '\n';
			return true;
		}
	}
	return false;
}
bool two(int n)
{
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (n == palindrome[i] + palindrome[j]) {
				cout << 2 << ' ' << palindrome[j] << ' ' << palindrome[i] << '\n';
				return true;
			}
		}
	}
	return false;
}
bool three(int n)
{
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			for (int k = 0; k < cnt; k++) {
				if (n == palindrome[i] + palindrome[j] + palindrome[k]) {
					cout << 3 << ' ' << palindrome[k] << ' ' << palindrome[j] << ' ' << palindrome[i] << '\n';
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	int N, T;
	cin >> T;
	//n이 10000이기 때문에 모든 회문을 미리 만듬. 모든 회문 개수가 200이 안되기 때문에 O(N^3)으로 해결
	for (int i = 1; i <= 10000; i++) {
		if (is_palindrome(i)) {
			palindrome[cnt] = i;
			cnt++;
		}
	}

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		cout << "Case #" << tc << '\n';
		if (!one(N) && !two(N) && !three(N)) {
			cout << '0' << '\n';
		}
	}
	return 0;
}