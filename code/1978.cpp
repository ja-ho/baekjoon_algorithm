#include <cstdio>

int COUNT;

bool prime(int n);

int main() {
	int N;
	int x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (prime(x)) COUNT++;
	}

	printf("%d", COUNT);
	return 0;

}

bool prime(int n) {
	if (n < 2) {
		return false;
	}

	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}

	return true;
}