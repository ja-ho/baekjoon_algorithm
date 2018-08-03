#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n, k;

bool check[100001];
int from[100001];

void print_ans(int next)
{
	if (next != n) {
		print_ans(from[next]);
	}
	cout << next << ' ';
	return;
}

int go()
{
	queue<int> q;
	q.push(n);
	check[n] = true;
	int cnt = 0;
	if (n == k) return 0;
	while (!q.empty()) {
		int length = q.size();
		cnt++;
		while (length--) {
			int now = q.front();
			q.pop();
			int temp[3] = { now - 1, now + 1, now * 2 };
			for (int i = 0; i < 3; i++) {
				int next = temp[i];
				if (next > 100000) continue;
				if (next < 0) continue;
				if (!check[next]) {
					check[next] = true;
					from[next] = now;
					q.push(next);
					if (next == k) {
						return cnt;
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> k;
	int answer = go();
	cout << answer << '\n';
	//stack<int> ans;

	//for (int i = k; i != n; i = from[i]) {
	//	ans.push(i);
	//}
	//ans.push(n);

	//while (!ans.empty()) {
	//	cout << ans.top() << ' ';
	//	ans.pop();
	//}
	print_ans(k);
	cout << '\n';
	return 0;
}