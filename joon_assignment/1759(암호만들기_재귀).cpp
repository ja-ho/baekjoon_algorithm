#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
vector<char> alphabet;

bool check(string str)
{
	int mo = 0;
	int ja = 0;
	int str_length = str.length();
	for (int i = 0; i < str_length; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') mo++;
		else ja++;
	}
	return (mo >= 1 && ja >= 2);
}


void go(int level, string now, int idx)
{
	if (level == l) {
		if (check(now)) {
			cout << now << '\n';
		}
		return;
	} 
	if (idx == c) return;
	go(level + 1, now + alphabet[idx], idx + 1);
	go(level, now, idx + 1);
}


int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char temp;
		cin >> temp;
		alphabet.push_back(temp);
	}

	sort(alphabet.begin(), alphabet.end());
	go(0, "", 0);


	return 0;
}