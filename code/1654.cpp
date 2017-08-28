#include <cstdio>

long long lanCableLength[10001];

bool check(long long divisor);

int N, K;


int main() {
	long long max = 0;

	scanf("%d %d", &K, &N);
	
	for (int i = 0; i < K; i++) {
		scanf("%lld", &lanCableLength[i]);
		if (max < lanCableLength[i]) {
			max = lanCableLength[i];
		}
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


bool check(long long divisor) {
	long long count = 0;
	for (int i = 0; i < K; i++) {
		count += lanCableLength[i] / divisor;
	}

	return count >= N;
}