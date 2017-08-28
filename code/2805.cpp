#include <cstdio>

long long trees[1000001];

long long N, M;

bool check(long long key);

int main() {
	long long max = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &trees[i]);
		if (max < trees[i]) max = trees[i];
	}

	long long first = 1;
	long long end = max;

	long long answer = 0;

	while (first <= end) {
		long long mid = (first + end) / 2;
		if (check(mid)) {
			if (answer < mid) {
				answer = mid;
			}
			first = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}

	printf("%lld", answer);


	return 0;
}

bool check(long long key) {
	long long count = 0;
	for (int i = 0; i < N; i++) {
		if (key < trees[i]) {
			count += trees[i] - key;
		}
	}
	return count >= M;
}