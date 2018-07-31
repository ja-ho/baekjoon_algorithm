#include <iostream>
#include <vector>
using namespace std;

int calc_degree(long long n, vector<int> &nums)
{
	int cnt = 0;
	while (n) {
		nums.push_back(n % 10);
		n /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	long long n;
	vector<int> nums;
	cin >> s >> n;
	int degree = calc_degree(n, nums);

	for (int i = 0; i < degree / 2; i++) {
		int temp = nums[degree - i - 1];
		nums[degree - i - 1] = nums[i];
		nums[i] = temp;
	}

	for (int j = 0; j < 2 * s + 3; j++) {
		int idx = 0;
		for (int x = 0; x < degree; x++) {
			if (j == 0) {
				if (nums[idx] == 1 || nums[idx] == 4) {
					for (int i = 0; i < s + 2; i++) cout << ' ';
				}
				else {
					cout << ' ';
					for (int i = 0; i < s; i++) cout << '-';
					cout << ' ';
				}
			}
			else if (j == 2 * s + 2) {
				if (nums[idx] == 1 || nums[idx] == 4 || nums[idx] == 7) {
					for (int i = 0; i < s + 2; i++) cout << ' ';
				}
				else {
					cout << ' ';
					for (int i = 0; i < s; i++) cout << '-';
					cout << ' ';
				}
			}
			else if (j < (2 * s + 3) / 2) {
				if (nums[idx] == 1 || nums[idx] == 2 || nums[idx] == 3 || nums[idx] == 7) {
					for (int i = 0; i < s + 1; i++) cout << ' ';
					cout << '|';
				}
				else if (nums[idx] == 5 || nums[idx] == 6) {
					cout << '|';
					for (int i = 0; i < s + 1; i++) cout << ' ';
				}
				else {
					cout << '|';
					for (int i = 0; i < s; i++) cout << ' ';
					cout << '|';
				}
			}
			else if (j > (2 * s + 3) / 2) {
				if (nums[idx] == 1 || nums[idx] == 3 || nums[idx] == 4 || nums[idx] == 5 || nums[idx] == 7
					|| nums[idx] == 9) {
					for (int i = 0; i < s + 1; i++) cout << ' ';
					cout << '|';
				}
				else if (nums[idx] == 2) {
					cout << '|';
					for (int i = 0; i < s + 1; i++) cout << ' ';
				}
				else {
					cout << '|';
					for (int i = 0; i < s; i++) cout << ' ';
					cout << '|';
				}
			}
			else if (j == (2 * s + 3) / 2) {
				if (nums[idx] == 1 || nums[idx] == 7 || nums[idx] == 0) {
					for (int i = 0; i < s + 2; i++) cout << ' ';
				}
				else {
					cout << ' ';
					for (int i = 0; i < s; i++) cout << '-';
					cout << ' ';
				}
			}
			idx++;
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}