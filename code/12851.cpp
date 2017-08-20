#include <cstdio>
#include <queue>
using namespace std;

bool visit[111111];
int d[111111];
int MAX = 100000;
int COUNT[111111];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	queue<int> q;
	q.push(N);
	visit[N] = true;
	d[N] = 0;
	COUNT[N] = 1;
	while (!q.empty()) {
		int currentPosition = q.front();
		q.pop();
		if (currentPosition * 2 <= MAX) {
			if (visit[currentPosition * 2] == false) {
				q.push(currentPosition * 2);
				visit[currentPosition * 2] = true;
				d[currentPosition * 2] = d[currentPosition] + 1;
				COUNT[currentPosition * 2] = COUNT[currentPosition];

			}
			else if (d[currentPosition * 2] == d[currentPosition] + 1){
				COUNT[currentPosition * 2] += COUNT[currentPosition];
			}

		}

		if (currentPosition + 1 <= MAX) {
			if (visit[currentPosition + 1] == false) {
				q.push(currentPosition + 1);
				visit[currentPosition + 1] = true;
				d[currentPosition + 1] = d[currentPosition] + 1;
				COUNT[currentPosition + 1] = COUNT[currentPosition];
			}
			else if (d[currentPosition + 1] == d[currentPosition] + 1) {
				COUNT[currentPosition + 1] += COUNT[currentPosition];
			}	
		}

		if (currentPosition - 1 >= 0) {
			if (visit[currentPosition - 1] == false) {
				q.push(currentPosition - 1);
				visit[currentPosition - 1] = true;
				d[currentPosition - 1] = d[currentPosition] + 1;
				COUNT[currentPosition - 1] = COUNT[currentPosition];

			}
			else if (d[currentPosition - 1] == d[currentPosition] + 1) {
				COUNT[currentPosition - 1] += COUNT[currentPosition];
			}
			
		}
	}

	printf("%d\n", d[K]);
	printf("%d\n", COUNT[K]);

	return 0;

}