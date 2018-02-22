#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int la, lb;
	string a, b;
	int **lcs;
	cin >> la >> lb;
	lcs = (int **)malloc(sizeof(int *) * (la + 1));
	for (int i = 0; i <= la; i++) {
		lcs[i] = (int *)malloc(sizeof(int)* (lb + 1));
	}

	cin >> a >> b;
	for (int i = 0; i <= la; i++) {
		memset(lcs[i], 0, sizeof(lcs[i]) * (lb + 1));
	}
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i] == b[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	printf("%d\n", lcs[la][lb]);


	for (int i = 0; i <= la; i++) {
		free(lcs[i]);
	}
	free(lcs);
	return 0;
}