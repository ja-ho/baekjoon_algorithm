#include <cstdio>

int N, L;
int map[101][101];

int temp_abs(int a, int b) {
	if (a - b < 0) {
		return -(a - b);
	}
	else
		return a - b;
}

int x_go() {
	int x_root = 0;
	for (int i = 1; i <= N; i++) {
		int same_level = 1;		//지나온 연속된 평평한 땅이 몇개인지
		bool possible = true;			//지나온 칸의 수
		for (int j = 1; j <= N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				same_level++;
			}
			else if (temp_abs(map[i][j], map[i][j+1]) > 1) {
				possible = false;
				break;
			}
			else {
				if (map[i][j] < map[i][j + 1]) {
					if (same_level < L) {
						possible = false;
						break;
					}
					same_level = 1;
				}
				else {
					if (j + L > N) {
						possible = false;
						break;
					} 
					else {
					
						bool enough = true;
						for (int k = j + 1; k <= j + L - 1; k++) {
							if (map[i][k] != map[i][k + 1]) {
								enough = false;
								break;
							}
						}
						if (enough == false) {
							possible = false;
							break;
						}
						same_level = 0;
						j += L - 1;
					}
				}
			}
		}
		if (possible) {
			x_root++;
		}
	}
	return x_root;
}

int y_go() {
	int y_root = 0;
	for (int j = 1; j <= N; j++) {
		int same_level = 1;		//지나온 연속된 평평한 땅이 몇개인지
		bool possible = true;			//지나온 칸의 수
		for (int i = 1; i <= N - 1; i++) {
			if (map[i][j] == map[i + 1][j]) {
				same_level++;
			}
			else if (temp_abs(map[i][j], map[i + 1][j]) > 1) {
				possible = false;
				break;
			}
			else {
				if (map[i][j] < map[i + 1][j]) {
					if (same_level < L) {
						possible = false;
						break;
					}
					same_level = 1;
				}
				else {
					if (i + L > N) {
						possible = false;
						break;
					}
					else {

						bool enough = true;
						for (int k = i + 1; k <= i + L - 1; k++) {
							if (map[k][j] != map[k + 1][j]) {
								enough = false;
								break;
							}
						}
						if (enough == false) {
							possible = false;
							break;
						}
						same_level = 0;
						i += L - 1;
					}
				}
			}
		}
		if (possible) {
			y_root++;
		}
	}
	return y_root;
}


int main() {
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int answer = x_go() + y_go();
	printf("%d\n", answer);
	return 0;
}