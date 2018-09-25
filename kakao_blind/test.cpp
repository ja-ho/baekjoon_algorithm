#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int cnt[502] = { 0, };

	int totalcnt = stages.size();
	for (int i = 0; i < totalcnt; i++) {
		cnt[stages[i]]++;
	}

	double rate[502] = { 0, };
	int challenger = 0;
	for (int i = 1; i <= N; i++) {
		if (totalcnt == challenger) rate[i] == 0;
		else {
			rate[i] = (double)(cnt[i]) / (totalcnt - challenger);
			challenger += (cnt[i]);
		}
	}

	vector<pair<double, int>> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(make_pair(rate[i], i));
		cout << rate[i] << " " << i << endl;
	}
	sort(v.begin(), v.end());
	for (int i = N; i > 0; i--) {
		answer.push_back(abs(v[i].second));
	}


	return answer;
}

int main() {

	int n = 5;
	vector<int> stages = { 2,1,2,6,2,4,3,3 };
	auto it = solution(n, stages);


}