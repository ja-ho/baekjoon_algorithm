#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare_second(pair<int, int>p1, pair<int, int>p2)
{
	return p1.second < p2.second;
}

int solution(vector<int> food_times, long long k) {
	int food_length = food_times.size();
	vector<pair<int, int>> v;
	for (int i = 0; i < food_length; i++) {
		v.push_back(make_pair(food_times[i], i + 1));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < food_length; i++) {
		long long remain = food_length - i;
		if (i == 0) {
			remain *= v[i].first;
		}
		else {
			remain *= v[i].first - v[i - 1].first;
		}
		if (k >= remain) {
			k -= remain;
		}
		else {
			sort(v.begin() + i, v.end(), compare_second);
			int idx = k % (food_length - i);
			return v[i + idx].second;
		}
	}
	return -1;
}

int main() {

	long long k = 10;
	vector<int> f = { 4, 3, 1, 4};
	auto it = solution(f, k);

	cout << it << '\n';
}