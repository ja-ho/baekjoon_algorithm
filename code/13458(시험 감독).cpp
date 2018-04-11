#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N;
int B, C;

vector<long long> A;
long long judge_count;

int go()
{
	int i = 1;
	bool visit = false;
	while (i <= N) {
		if (visit == false) {
			judge_count++;
			visit = true;
			A[i] -= B;
		}
		else if (A[i] > 0) {
			if (A[i] > C) {
				judge_count += A[i] / C;
				A[i] = A[i] % C;
			}
			else {
				judge_count++;
				i++;
				visit = false;
			}
		}
		else {
			i++;
			visit = false;
		}
	}
	return 0;
}

int main() {
	cin >> N;

	A.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		A[i] = temp;
	}
	
	cin >> B >> C;

	judge_count = 0;
	go();
	printf("%lld\n", judge_count);
	return 0;
}