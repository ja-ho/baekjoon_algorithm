#include <cstdio>

unsigned long long modular(int a, int b, int c);

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int answer = modular(a, b, c);
	printf("%d", answer);
}

unsigned long long modular(int a, int b, int c)
{
	if (b == 0) return 1;
	if (b % 2 == 1) return a * modular(a, b - 1, c) % c;
	else {
		unsigned long long half = modular(a, b / 2, c) % c;
		return (half%c*half%c) % c;
	}
}