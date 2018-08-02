#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;

bool check[100001];
int from[100001];

int go()
{
	queue<int> q;
	q.push(n);
	check[n] = true;
	int cnt = 0;
	from[n] = -1;
	if (n == k) return 0;
	while (!q.empty()) {
		int length = q.size();
		cnt++;
		while (length--) {
			int now = q.front();
			q.pop();
			int temp[3] = { now - 1, now + 1, now * 2 };
			for (int i = 0; i < 3; i++) {
				int now = temp[i];
				if (now == k) {
					return cnt;
				}
				if (now > 100000) continue;
				if (now < 0) continue;
				if (!check[now]) {
					check[now] = true;
					q.push(now);
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
	return 0;
}