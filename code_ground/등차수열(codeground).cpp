#include <iostream>
#include <vector>
using namespace std;

int Answer;
int M;
vector<long long> sequence;
vector<long long> diff;

//euclidean algorithm
long long GCD(long long x, long long y)
{
	if (y == 0) return x;
	else
	{
		return GCD(y, x%y);
	}
}

bool check_zero()
{
	int cnt = 0;
	for (int i = 1; i < M; i++) {
		if (sequence[i] == sequence[i + 1]) {
			cnt++;
		}
	}
	if (cnt != 0) {
		if (cnt == M - 1)
		{
			Answer++;
			return false;
		}
		else return false;
	}
	return true;
}


void go() 
{
	Answer = 0;
	int max_divisor;
		
	if (!check_zero()) 
		return;	//등차수열이 존재하지 않는 경우 체크

	for (int i = 1; i < M; i++) {
		diff[i - 1] = sequence[i + 1] - sequence[i];
	}
	
	max_divisor = GCD(diff[0], diff[1]);

	for (int i = 2; i < M - 1; i++) {
		max_divisor = GCD(diff[i], max_divisor);
	}
	for (int i = 1; i*i <= max_divisor; i++) {
		if (max_divisor % i == 0) {
			Answer++;
			if (i != (max_divisor / i)) {
				Answer++;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> M;

		sequence.clear();
		diff.clear();
		sequence.resize(M + 1);
		diff.resize(M + 1);

		for (int i = 1; i <= M; i++) {
			cin >> sequence[i];
		}

		go();


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}