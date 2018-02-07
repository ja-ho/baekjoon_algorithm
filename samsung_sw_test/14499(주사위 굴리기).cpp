#include <cstdio>
#include <queue>
using namespace std;

int map[22][22];
int dice[6];	//0: À­¸é 5: ¾Æ·§¸é 1:À­¸é±âÁØºÏ 2:À­¸é±âÁØ µ¿ 3: À­¸é±âÁØ¼­ 4:À­¸é±âÁØ³²
int N, M;
queue<int> command;

void roll(int dir) {
	if (dir == 1) {
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	else if (dir == 2) {
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}
	else if (dir == 3) {
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	else {
		int temp = dice[0];
		dice[0] = dice[1];		//0: À­¸é 5: ¾Æ·§¸é 1:À­¸é±âÁØºÏ 2:À­¸é±âÁØ µ¿ 3: À­¸é±âÁØ¼­ 4:À­¸é±âÁØ³²
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
	}
}

void go(int *x, int *y) {
	int comm = command.front();
	command.pop();
	if (comm == 1) {			//µ¿
		if (*x >= M - 1) return;
		(*x)++;
		roll(1);
	}
	else if (comm == 2) {	//¼­
		if (*x <= 0) return;
		(*x)--;
		roll(2);
	}
	else if (comm == 3) {	//ºÏ
		if (*y <= 0) return;
		(*y)--;
		roll(3);
	}
	else {						//³²
		if (*y >= N - 1) return;
		(*y)++;
		roll(4);
	}
	if (map[*y][*x] == 0) {
		map[*y][*x] = dice[5];
	}
	else {
		dice[5] = map[*y][*x];
		map[*y][*x] = 0;
	}
	printf("%d\n", dice[0]);
}


int main() {
	int x, y, K;
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int temp;
		scanf("%d", &temp);
		command.push(temp);
	}

	while (K--) {
		go(&x, &y);
	}

	
	return 0;
}