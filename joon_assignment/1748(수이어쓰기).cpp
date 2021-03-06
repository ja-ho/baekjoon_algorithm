#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long cnt = 0;
	
	for (int start = 1, len = 1; start <= N; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > N) {
			end = N;
		}
		cnt += (end - start + 1) * len;
	}
	cout << cnt << '\n';
	return 0;
}