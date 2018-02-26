#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int Answer;
string search_string;
string find_string;

int find()
{
	int length = find_string.length();
	int cnt = 0;
	for (int i = 0; i < length; i++) {
		if (find_string[i] == search_string[0]) {
			bool check = true;
			for (int j = 0; j < search_string.length(); j++) {
				if (search_string[j] != find_string[i + j]) {
					check = false;
					break;
				}
			}
			if (check) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int T;
	for (int tc = 1; tc <= 10; tc++) {
		Answer = 0;
		search_string.clear();
		find_string.clear();
		cin >> T;
		cin >> search_string;
		cin >> find_string;

		Answer = find();		

		cout << "#" << T << " " << Answer << endl;
	}
	return 0;
}