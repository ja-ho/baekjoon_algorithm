#include <iostream>
#include <cstdio>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
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

	return 0;//Your program should return 0 on normal termination.
}

