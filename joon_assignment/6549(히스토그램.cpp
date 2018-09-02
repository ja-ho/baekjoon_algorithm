#include <iostream>
#include <stack>
using namespace std;

int square[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int tmp;
	int width, height, right;
	while (1) {
		cin >> n;
		long long max_area = 0;
		stack<int> st;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> square[i];
			while (!st.empty() && square[st.top()] > square[i]) {
				height = square[st.top()];
				width = i;
				st.pop();
				if (!st.empty()) width = i - st.top() - 1;
				if (max_area < width * (long long)height) max_area = width * (long long)height;
			}
			st.push(i);
		}
		while (!st.empty()) {
			height = square[st.top()];
			width = n;
			st.pop();
			if (!st.empty()) width = n - st.top() - 1;
			if (max_area < width * (long long)height) max_area = width * (long long)height;
		}
		cout << max_area << '\n';
	}
	return 0;
}