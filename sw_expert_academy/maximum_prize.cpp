#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char prize[6];
int answer;
int number;
int over;

void swap(char *arr, int i, int j)
{
	char temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void go(char prize[6], int depth)
{
	over++;
	if (over > 10000) return;
	if (depth == number) {
		if (answer < atoi(prize)) {
			answer = atoi(prize);
			return;
		}
		return;
	}
	int length = strlen(prize);
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			swap(prize, i, j);
			go(prize, depth + 1);
			swap(prize, i, j);
		}
	}
}

int main() {
	int T;
	int tc;
	cin >> T;

	for (tc = 0; tc < T; tc++) {
		int length = 0;
		int cnt = 0;
		answer = 0;
		over = 0;
		memset(prize, 0, sizeof(prize));
		cin >> prize >> number;
		length = strlen(prize);
		go(prize, 0);

		cout << "#" << tc + 1 << " " << answer << endl;
	}

	return 0;
}