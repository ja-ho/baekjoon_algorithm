#include <iostream>
using namespace std;

int	number[11];
int sign[4];
int N;
int MAX;
int MIN;

void dfs(int num, int *sign, int level) {
	int *tempSign;
	int nextNum;
	if (level == N - 1) {
		if (num > MAX) MAX = num;
		if (num < MIN) MIN = num;
		return;
	}
	nextNum = number[level + 1];
	for (int i = 0; i < 4; i++) {
		tempSign = new int[4];

		for (int j = 0; j < 4; j++) {
			tempSign[j] = sign[j];
		}

		if (tempSign[i] == 0) continue;
		if (i == 0) {
			tempSign[i]--;
			dfs(num + nextNum, tempSign, level + 1);
		}
		else if (i == 1) {
			tempSign[i]--;
			dfs(num - nextNum, tempSign, level + 1);
		}
		else if (i == 2) {
			tempSign[i]--;
			dfs(num * nextNum, tempSign, level + 1);
		}
		else if (i == 3) {
			tempSign[i]--;
			dfs(num / nextNum, tempSign, level + 1);
		}
	}

	delete[] tempSign;
}



int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> sign[i];
	}

	MAX = -1000000000;
	MIN = 1000000000;

	dfs(number[0], sign, 0);
	
	cout << MAX << endl << MIN << endl;
	
	return 0;
}