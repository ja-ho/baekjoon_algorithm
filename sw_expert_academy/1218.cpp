#include <iostream>
#include <string>
#include <stack>
using namespace std;

int Answer;

int go(int N)
{
	stack<char> s;
	int possible = 1;
	for (int i = 0; i < N; i++) {
		char ch;
		cin >> ch;
		if (ch == '(' || ch == '{' || ch == '[' || ch == '<') {
			s.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']' || ch == '>') {
			if (s.empty()) {
				continue;
			}
			char comp_ch = s.top();
			s.pop();
			if (ch == ')') {
				if (comp_ch != '(') {
					possible = 0;
				}
			}
			else if (ch == '}') {
				if (comp_ch != '{') {
					possible = 0;
				}
			}
			else if (ch == ']') {
				if (comp_ch != '[') {
					possible = 0;
				}
			}
			else if (ch == '>') {
				if (comp_ch != '<') {
					possible = 0;
				}
			}
		}
	}

	if (!s.empty()) {
		possible = 0;
	}

	return possible;
}


int main() {
	int N;
	int tc;
	freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		Answer = go(N);
		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}