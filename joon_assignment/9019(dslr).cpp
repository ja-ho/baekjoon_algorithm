#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


bool check[10001];
int history[10001];
char how[10001];

void print_how(int next, int a)
{
	if (next != a) {
		print_how(history[next], a);
	}
	if (how[next] == '\0') return;
	cout << how[next];
	return;
}


int calc(int a, int type)
{
	if (type == 0) {
		return (a * 2) % 10000;
	}
	else if (type == 1) {
		return (a - 1 == -1 ? 9999 : a - 1);
	}
	else if (type == 2) {	//L
		return ((a % 1000) * 10 + a / 1000);
	}
	else if (type == 3) {	//R
		return ((a / 10) + (a % 10 * 1000));
	}
}


int bfs(int a, int b)
{
	queue<int> reg;
	reg.push(a);
	check[a] = true;
	history[a] = -1;
	how[a] = '\0';
	int cnt = 0;
	while (!reg.empty()) {
		int length = reg.size();
		cnt++;
		while (length--) {
			int now = reg.front();
			reg.pop();
			int dy[4] = { calc(now, 0), calc(now, 1), calc(now, 2), calc(now, 3) };
			for (int i = 0; i < 4; i++) {
				int next = dy[i];
				if (check[next]) continue;
				check[next] = true;
				reg.push(next);
				history[next] = now;
				if (i == 0) how[next] = 'D';
				else if (i == 1) how[next] = 'S';
				else if (i == 2) how[next] = 'L';
				else if (i == 3) how[next] = 'R';
				if (next == b) return cnt;
			}
		}
		
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < 10001; i++) {
			check[i] = false;
			history[i] = 0;
			how[i] = '\0';
		}
		bfs(a, b);
		print_how(b, a);
		cout << '\n';
	}
	return 0;
}