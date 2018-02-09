#include <iostream>
#include <cstdio>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		int N;
		bool over;
		int cnt = 0;
		scanf("%d", &N);
	
		for (int i = 2; i*i <= N; i++) {	//n > 2일때
			cnt = 0;
			int tempN = N;
			over = true;
			int x = N%i;

			while (tempN > 0) {
				if (tempN%i != x) {
					over = false;
					break;
				}
				tempN /= i;
			}
			
			if (!over) {
				continue;
			}
			else {
				Answer = i;
				break;
			}
		}
									//n==2 일때
		if (!over) {
			for (int i = 1; i*i <= N; i++) {
				if (N%i != 0) continue;
				int b = N / i - 1;
				if (b > i) {
					Answer = b; 
				}
			}
		}
		
		if (Answer == 0) Answer = N + 1;

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;
}

