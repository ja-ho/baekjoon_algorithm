#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char character[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

typedef struct _command {
	char first;
	char second;
	char op;
	int num;
} command;

bool check(char first, char second, char op, int num)
{
	int cnt = 0;
	bool start_signal = false;
	for (int i = 0; i < 8; i++) {
		if (op == '=') {
			if (character[i] == first || character[i] == second) {
				if (!start_signal)
					start_signal = true;
				else if (start_signal) {
					if (cnt == num) return true;
					else return false;
				}				
			}
			else {
				if (start_signal) {
					cnt++;
				}
			}
		}
		else if (op == '>') {
			if (character[i] == first || character[i] == second) {
				if (!start_signal)
					start_signal = true;
				else if (start_signal) {
					if (cnt > num) return true;
					else return false;
				}
			}
			else {
				if (start_signal) {
					cnt++;
				}
			}
		}
		else if (op == '<') {
			if (character[i] == first || character[i] == second) {
				if (!start_signal)
					start_signal = true;
				else if (start_signal) {
					if (cnt < num) return true;
					else return false;
				}
			}
			else {
				if (start_signal) {
					cnt++;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	vector<command> commands;
	cin >> n;

	for (int i = 0; i < n; i++) {
		command tmp_command;
		string temp;
		cin >> temp;
		tmp_command.first = temp[0];
		tmp_command.second = temp[2];
		tmp_command.op = temp[3];
		tmp_command.num = temp[4] - '0';
		commands.push_back(tmp_command);
	}

	sort(character, character + 8);
	int ans = 0;
	do {
		bool is_right = true;
		for (int i = 0; i < n; i++) {
			char first = commands[i].first;
			char second = commands[i].second;
			char op = commands[i].op;
			int num = commands[i].num;
			if (!check(first, second, op, num)) {
				is_right = false;
				break;
			}
		}
		if (is_right) ans++;
	} while (next_permutation(character, character + 8));


	cout << ans << '\n';
	return 0;
}