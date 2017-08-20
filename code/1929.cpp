#include <stdio.h>
bool visit[1111111];

int main() {
	int M, N;
	int primeCount = 0;
	scanf("%d %d", &M, &N);
	visit[1] = true;
	for (int i = 2; i*i <= 1000000; i++) {
		if (visit[i] == false) {
			for (int j = 2 * i; j <= N; j += i) {
				visit[j] = true;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (visit[i] == false) {
			printf("%d\n", i);
		}
	}

	return 0;
}
