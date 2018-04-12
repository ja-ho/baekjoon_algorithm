#include <cstdio>
using namespace std;

int numbers[12];
int sign[4];
int N;

int MAX = -1000000000;
int MIN = 1000000000;

int calc(int level, int now, int sign) {
	if (sign == 0) {
		now += numbers[level];
	}
	else if (sign == 1) {
		now -= numbers[level];
	}
	else if (sign == 2) {
		now *= numbers[level];
	}
	else if (sign == 3) {
		now /= numbers[level];
	}
	return now;
}

void dfs(int level, int temp_sign[4], int now) {
	if (level == N) {
		if (now < MIN) {
			MIN = now;
		}
		if (now > MAX) {
			MAX = now;
		}
		return;
	}
		
	int temp_temp_sign[4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp_temp_sign[j] = temp_sign[j];
		}
		if (temp_sign[i]) {
			int temp_now = now;
			temp_now = calc(level, now, i);
			temp_temp_sign[i]--;
			dfs(level + 1, temp_temp_sign, temp_now);
		}
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &sign[i]);
	}

	dfs(1, sign, numbers[0]);
	
	printf("%d\n%d\n", MAX, MIN);

	return 0;
}