#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int Answer;
string search_string;
string find_string;

int find()
{




	return 0;
}



int main() {
	int T;
	string temp_strings;
	for (int tc = 1; tc <= 10; tc++) {
		Answer = 0;
		search_string.clear();
		find_string.clear();
		cin >> T;
		cin >> search_string;
		cin >> temp_strings;

		Answer = find();		

		cout << "#" << T << " " << Answer << endl;
	}
	return 0;
}