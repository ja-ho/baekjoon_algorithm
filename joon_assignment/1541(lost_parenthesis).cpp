#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	vector<int> nums;
	vector<char> sign;
	cin >> str;
	int str_length = str.size();
	int num = 0;
	sign.push_back('+');

	for (int i = 0; i < str_length; i++) {
		if (str[i] == '-' || str[i] == '+' || i == str_length - 1) {
			if (i == str_length - 1) {
				num *= 10;
				num += str[i] - '0';
			}
			else {
				sign.push_back(str[i]);
			}
			nums.push_back(num);
			num = 0;
		}
		else {
			num *= 10;
			num += str[i] - '0';
		}
	}

	bool minus = false;
	int ans = 0;
		
	for (int i = 0; i < nums.size(); i++) {
		if (sign[i] == '-') {
			minus = true;
		}
		if (minus) {
			ans -= nums[i];
		}
		else {
			ans += nums[i];
		}
	}
	cout << ans << '\n';
	return 0;
}