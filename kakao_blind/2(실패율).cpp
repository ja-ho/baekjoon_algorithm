#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int people = stages.size();
	vector<int>v(N + 2, 0);
	for (int i = 0; i < people; i++) {
		v[stages[i]]++;
	}
	vector<pair<double, int>>fail_prob;
	for (int i = 1; i <= N; i++) {
		double prob = 0;
		prob = (double)v[i] / people;
		people -= v[i];
		fail_prob.push_back(make_pair(-prob, i));
	}
	sort(fail_prob.begin(), fail_prob.end());
	for (int i = 0; i < N; i++) {
		answer.push_back(fail_prob[i].second);
	}
	return answer;
}

int main() {
	int n = 4;
	vector<int> stages = { 4, 4, 4, 4 };
	auto it = solution(n, stages);

	return 0;
}