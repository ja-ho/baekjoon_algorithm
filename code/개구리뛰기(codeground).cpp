#include <iostream>
#include <stdlib.h>

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

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer
		*/
		////////////////////////////////////////////////////////////////////////////////////////////
		int N;
		int *rocks;
		int K;
		int now = 0;
		int rocksNow = 0;
		int max_jump_once;
		bool over = false;
		bool possible;
		cin >> N;
		rocks = (int *)malloc(sizeof(int)*(N+1));
		for (int i = 1; i <= N; i++) {
			cin >> rocks[i];
		}
		rocks[0] = 0;	//initial
		cin >> K;
		
		while (!over) {
			possible = false;
			max_jump_once = 0;
			for (int i = rocksNow + 1; i <= N; i++) {
				if (rocks[i] - now <= K) {
					if (i == N) {
						over = true;
						Answer++;
					}
					if (rocks[i] - now > max_jump_once) {
						max_jump_once = rocks[i] - now;
						possible = true;
						rocksNow = i;
					}
				}
				else break;
			}
			if (!possible) {
				break;
			}
			if (!over) {
				now = rocks[rocksNow];
				Answer++;
			}
		}

		if (!possible) {	//can't go
			cout << "Case #" << test_case + 1 << endl;
			cout << -1 << endl;
			continue;
		}


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		free(rocks);
	}

	return 0;//Your program should return 0 on normal termination.
}