#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> josepers;
	queue<int> out_char;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		josepers.push(i);
	}
	cout << "<";
	while (!josepers.empty()) {
		for (int i = 0; i < M - 1; i++) {
			int temp = josepers.front();
			josepers.pop();
			josepers.push(temp);
		}
		if (josepers.size() == 1) {
			cout << josepers.front() << ">\n";
			josepers.pop();
		}
		else {
			cout << josepers.front() << ", ";
			josepers.pop();
		}
	}
	return 0;
}