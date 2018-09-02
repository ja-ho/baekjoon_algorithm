#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	priority_queue<int, vector<int>> left;
	priority_queue<int, vector<int>> right;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (left.size() == 0) left.push(x);
		else {
			if (left.top() > x) left.push(x);
			else right.push(-x);
			if (left.size() != right.size()) {
				if (right.size() > left.size()) {
					left.push(-right.top());
					right.pop();
				}
				else if (left.size() != right.size() + 1) {
					right.push(-left.top());
					left.pop();
				}
			}
		}
		cout << left.top() << '\n';
	}
	return 0;
}