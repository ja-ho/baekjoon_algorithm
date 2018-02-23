#include <iostream>
using namespace std;

int Answer;	//answer == 0 -> win_alice, answer == 1 -> win->bob

void predict(long long N) 
{

	if (N == 1) {
		Answer = 1;
		return;
	}
	else if (N < 3) {
		Answer = 0;
		return;
	}
	else {
		long long x = 1;
		long long temp = N;
		int cnt = 0;
		while (temp /= 2) {
			cnt++;
		}
		if (cnt % 2 == 0) {	//bobÀÇ Â÷·Ê
			cnt /= 2;
			while (cnt--) {
				x = 2 * x + 1;
				x = 2 * x;
			}
			if (x <= N) {
				Answer = 1;
			}
			else Answer = 0;
		}
		else {	//aliceÀÇ Â÷·Ê
			cnt /= 2;
			while (cnt--) {
				x = 2 * x;
				x = 2 * x + 1;
			}
			x = 2 * x;
			if (x <= N) Answer = 0;
			else Answer = 1;
		}
	}
}

int main() {
	int T;
	int tc;
	cin >> T;
	for (tc = 0; tc < T; tc++) {
		long long N;
		Answer = 0;
		cin >> N;

		predict(N);
		
		if (Answer == 0) {
			cout << "#" << tc + 1 << " Alice" << endl;
		}
		else {
			cout << "#" << tc + 1 << " Bob" << endl;
		}
	}
	return 0;
}