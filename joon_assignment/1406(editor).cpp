#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
	//for input, output
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string ss;
	stack<char> left;
	stack<char> right;
	int N;
	cin >> ss;
	cin >> N;
	int s_length = ss.length();

	for (int i = 0; i < s_length; i++) {
		left.push(ss[i]);
	}

	for (int i = 0; i < N; i++) {
		char command;
		cin >> command;
		if (command == 'L') {
			if (left.empty());
			else {
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == 'D') {
			if (right.empty());
			else {
				left.push(right.top());
				right.pop();
			}
		}
		else if (command == 'B') {
			if (left.empty());
			else {
				left.pop();
			}
		}
		else if (command == 'P') {
			char temp;
			cin >> temp;
			left.push(temp);
		}
	}

	stack<char> reverse;
	int left_length = left.size();
	int right_length = right.size();
	for (int i = 0; i < left_length; i++) {
		reverse.push(left.top());
		left.pop();
	}
	for (int i = 0; i < left_length; i++) {
		cout << reverse.top();
		reverse.pop();
	}

	for (int i = 0; i < right_length; i++) {
		cout << right.top();
		right.pop();
	}
	cout << '\n';
	return 0;
}