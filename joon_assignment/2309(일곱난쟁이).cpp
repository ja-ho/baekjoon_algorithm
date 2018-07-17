#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> height;
	int total = 0;
	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		height.push_back(temp);
		total += temp;
	}
	
	int not_1 = -1, not_2;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			int two_height = height[i] + height[j];
			if ((total - two_height) == 100) {
				not_1 = height[i]; not_2 = height[j];
				break;
			}
		}
		if (not_1 != -1) {
			break;
		}
	}

	sort(height.begin(), height.end());
	for (int i = 0; i < 9; i++) {
		if (height[i] != not_1 && height[i] != not_2) {
			cout << height[i] << '\n';
		}
	}
	return 0;
}