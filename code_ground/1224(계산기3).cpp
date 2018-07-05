#include <iostream>
#include <string>
#include <stack>
using namespace std;

string ss;

int calc_bracket(int *idx)
{
	stack<int> temp_st;
	while (ss[*idx] != ')') {
		if (ss[*idx] >= 48) temp_st.push(ss[*idx] - 48);
		else if (ss[*idx] == '*') {
			int temp = temp_st.top();
			temp_st.pop();
			if (ss[*idx + 1] - 48 >= 0) temp *= ss[*idx + 1] - 48;
			else {
				(*idx) += 2;
				temp *= calc_bracket(idx);
				(*idx)--;
			}
			(*idx)++;
			temp_st.push(temp);
		}
		else if (ss[*idx] == '(') {
			(*idx)++;
			int temp = calc_bracket(idx);
			temp_st.push(temp);
		}
		(*idx)++;
	}
	int ret_answer = 0;

	while (!temp_st.empty()) {
		ret_answer += temp_st.top();
		temp_st.pop();
	}
	return ret_answer;
}


int main() {
	for (int tc = 1; tc <= 10; tc++) {
		stack<int> num_st;
		int str_length;
		int answer = 0;
		cin >> str_length;
		cin >> ss;
		for (int i = 0; i < str_length; i++) {
			if (ss[i] >= 48) num_st.push(ss[i] - 48);

			if (ss[i] == '*') {
				int temp = num_st.top();
				num_st.pop();
				temp *= ss[i + 1] - 48;
				i++;
				num_st.push(temp);
			}
			else if (ss[i] == '(') {
				i++;
				int temp = calc_bracket(&i);
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