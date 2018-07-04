#include <iostream>
#include <stack>
#include <string>
using namespace std;

//using stack

//int main() {
//	string ss;
//	stack<char> lazer;
//	cin >> ss;
//	int s_length = ss.length();
//	int cnt = 0;
//	for (int i = 0; i < s_length; i++) {
//		if (ss[i] == '(') {
//			lazer.push(ss[i]);
//		}
//		else if (ss[i] == ')' && i >= 1) {
//			if (ss[i - 1] == '(') {
//				cnt += lazer.size() - 1;
//				lazer.pop();
//			}
//			else {
//				lazer.pop();
//				cnt += 1;
//			}
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}

//using variable
int main() {
	string ss;
	cin >> ss;
	int s_length = ss.length();
	int stick = 0;
	int cnt = 0;
	for (int i = 0; i < s_length; i++) {
		if (ss[i] == '(') {
			stick++;
		}
		else if (ss[i] == ')' && i >= 1) {
			if (ss[i - 1] == '(') {
				cnt += stick - 1;
				stick--;
			}
			else {
				stick--;
				cnt += 1;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}