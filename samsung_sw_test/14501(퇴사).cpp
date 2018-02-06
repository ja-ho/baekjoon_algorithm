#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int N;
int job[17][2];
int d[17];
int MAX;

//dp 풀이
int dp() {
	int t, p;
	//initialize

	//recurrence relation
	for (int i = N; i >= 1; i--) {		//기한 걸려있는 것은 역순으로 생각해보자
		t = job[i][0];
		p = job[i][1];
		d[i] = d[i + 1];
		if (N - i + 1 >= t) {
			d[i] = MAX(d[i], d[i + t] + p);
		}
		else continue;
	}
	return d[1];
}

int main() {
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		int day, pay;
		scanf("%d %d", &job[i][0], &job[i][1]);
	}
	int max_profit = dp();
	printf("%d\n", max_profit);

	return 0;
}