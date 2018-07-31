#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char sign[20];
vector<string> answer;
bool check[10];
int k;

bool possible(char a, char b, char op)
{
	if (op == '<') {
		if (a > b) return false;
	}
	if (op == '>') {
		if (a < b) return false;
	}
	return true;
}

void calc(int idx, string num)
{
	if (idx == k + 1) {
		answer.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue;
		if (idx == 0 || possible(num[idx - 1], i + '0', sign[idx - 1])) {
			check[i] = true;
			calc(idx + 1, num + to_string(i));
			check[i] = false;
		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> sign[i];
	}
	
	calc(0, "");
	auto ans = minmax_element(answer.begin(), answer.end());
	cout << *ans.second << '\n';
	cout << *ans.first << '\n';
	return 0;
}