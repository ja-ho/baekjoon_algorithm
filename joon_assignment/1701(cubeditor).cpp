#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int preprocessing(char *t)
{
	int m = strlen(t);
	vector<int> pi(m);
	int j = 0;
	int max = 0;
	pi[0] = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && t[i] != t[j]) {
			j = pi[j - 1];
		}
		if (t[i] == t[j]) {
			pi[i] = j + 1;
			j++;
			if (max < pi[i]) max = pi[i];
		}
		else {
			pi[i] = 0;
		}
	}
	return max;
}


int main() {
	char str[5001];
	cin >> str;
	int str_len = strlen(str);
	int max = 0;
	for (int i = 0; i < str_len; i++) {
		//if (str_len - i + 1 < max) break; 안하는게 더 빠르네
		int tmp_max = preprocessing(str + i);
		if (max < tmp_max) max = tmp_max;
	}
	cout << max << '\n';
	return 0;
}