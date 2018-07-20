#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	int set_num = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string command;
		int tmp;
		cin >> command;
		if (command == "add") {
			cin >> tmp;
			set_num = (set_num | (1 << tmp));
		}
		else if (command == "remove") {
			cin >> tmp;
			set_num = (set_num & ~(1 << tmp));
		}
		else if (command == "check") {
			cin >> tmp;
			if ((set_num & (1 << tmp))) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "toggle") {
			cin >> tmp;
			set_num = (set_num ^ (1 << tmp));
		}
		else if (command == "all") {
			set_num = (1 << 21) - 1;
		}
		else if (command == "empty") {
			set_num = 0;
		}
	}
	return 0;
}