#include <stdio.h>
#include <queue>
using namespace std;

int MAX = 1000000;
int d[1000000];
bool visit[1000000];

int main() {
	int N, K;
	queue<int> q;
	queue<int> next_q;

	scanf("%d %d", &N, &K);
	visit[N] = true;
	d[N] = 0;
	q.push(N);
	while (!q.empty()) {
		int currentPosition = q.front();
		q.pop();

		if (currentPosition * 2 < MAX && visit[currentPosition * 2] == false) {
			visit[currentPosition * 2] = true;
			q.push(currentPosition * 2);
			d[currentPosition * 2] = d[currentPosition];
		}


		if (currentPosition - 1 >= 0 && visit[currentPosition - 1] == false) {
			visit[currentPosition - 1] = true;
			next_q.push(currentPosition - 1);
			d[currentPosition - 1] = d[currentPosition] + 1;
		}

		if (currentPosition + 1 < MAX && visit[currentPosition + 1] == false) {
			visit[currentPosition + 1] = true;
			next_q.push(currentPosition + 1);
			d[currentPosition + 1] = d[currentPosition] + 1;

		}

		if (q.empty()) {
			q = next_q;
			next_q = queue<int>();
		}

	}

	printf("%d\n", d[K]);

	return 0;
}

