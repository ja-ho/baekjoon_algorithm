#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nums;
int n;
int max_num, min_num;

void go(int idx, int now, int plus, int minus, int mult, int div)
{
	if (idx == n) {
		max_num = max(now, max_num);
		min_num = min(now, min_num);
	}
	int temp;
	if (plus > 0) {
		go(idx + 1, now + nums[idx], plus - 1, minus, mult, div);
	}
	if (minus > 0) {
		go(idx + 1, now - nums[idx], plus, minus - 1, mult, div);
	}
	if (mult > 0) {
		go(idx + 1, now * nums[idx], plus, minus, mult - 1, div);
	}
	if (div > 0) go(idx + 1, now / nums[idx], plus, minus, mult, div - 1);
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	int plus,minus, mult, div;

	cin >> plus; cin >> minus; cin >> mult; cin >> div;

	max_num = -1000000000;
	min_num = 1000000000;
	go(1, nums[0], plus, minus, mult, div);
	cout << max_num << '\n' << min_num << '\n';
	return 0;
}