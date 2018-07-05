#include <iostream>
#include <string>

using namespace std;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int answer = 0;
		string ss;
		int str_length;
		cin >> str_length;
		cin >> ss;
		for (int i = 0; i < str_length - 1; i++) {
			if (i % 2 == 0) {
				answer += ss[i] - 48;
			}
		}
		answer += ss[str_length - 1] - 48;

		cout << "#" << tc << " " << answer << '\n';
	}
	return 0;
}