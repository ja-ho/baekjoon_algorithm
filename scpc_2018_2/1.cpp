#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int Answer;
int nums[222222];
int N;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, test_case;
	cin >> t;
	for (test_case = 0; test_case < t; test_case++)
	{
		Answer = 0;
		int max_num;
		stack<int> st;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}

		st.push(nums[0]);
		max_num = nums[0];
		for (int i = 1; i < N; i++) {
			if (nums[i] > max_num) {
				max_num = nums[i];
				st.push(max_num);
			}
			else {
				if (!st.empty()) {
					while (st.top() > nums[i]) {
						st.pop();
						if (st.empty()) break;
					}
				}
			}
		}
		Answer = st.size();
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}