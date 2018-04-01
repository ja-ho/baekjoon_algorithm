#include <iostream>
using namespace std;

int Answer;

int go(int N, int M) 
{
	if (M == 0) {
		return 1;
	}
	
	return N * go(N, M - 1);
}

int main()
{
	for (int tc = 1; tc <= 10; tc++) {
		int T;
		cin >> T;
		int N, M;
		cin >> N >> M;

		Answer = go(N, M);

		cout << "#" << T << " " << Answer << endl;
	}
	return 0;
}