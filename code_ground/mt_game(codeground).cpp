#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<char> answer;

void go(int a, int b, int c, int N, int K) 
{
	if (N <= a) {
		answer.push_back('b');
		return;
	}

	if (K == 1) {
		int remainder = N % (a + b);
		if (remainder == 0) answer.push_back('a');
		else if (remainder < a) answer.push_back('b');
		else answer.push_back('a');
		return;
	}
	if (a > b) {
		if (N > a) {
			answer.push_back('a');
		}
		else answer.push_back('b');
	}
	else
	{ 
		int remainder = N % ((K + 1) * a);
		if (remainder == 0 || remainder > a) answer.push_back('a');
		else answer.push_back('b');
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int a, b, c;
		int N, K;
		scanf("%d %d %d", &a, &b, &c);
		answer.clear();

		for (int i = 0; i < c; i++) {
			scanf("%d %d", &N, &K);
			go(a, b, c, N, K);
		}


		cout << "Case #" << test_case + 1 << endl;
		for (int i = 0; i < answer.size(); i++) {
			printf("%c", answer[i]);
		}
		printf("\n");

	}

	return 0;
}