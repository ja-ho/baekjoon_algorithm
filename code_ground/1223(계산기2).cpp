#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		stack<int> num_st;
		string ss;
		int str_length;
		int answer = 0;

		cin >> str_length;
		cin >> ss;
		for (int i = 0; i < str_length; i++) {
			if (i % 2 == 0) num_st.push(ss[i] - 48);

			if (ss[i] == '*') {
				int temp = num_st.top();
				num_st.pop();
				temp *= ss[i + 1] - 48;
				i++;
				num_st.push(temp);
			}
		}

		while (!num_st.empty()) {
			answer += num_st.top();
			num_st.pop();
		}
		cout << "#" << tc << " " << answer << '\n';
	}
	return 0;
}