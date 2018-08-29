#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> preprocessing(string p)
{
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j++;
		}
		else {
			pi[i] = 0;
		}
	}
	return pi;
}

vector<int> kmp(string s, string p)
{
	vector<int> ans;
	int n = s.size();
	int m = p.size();
	int i = 0;
	int j = 0;
	auto pi = preprocessing(p);

	for (i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main() {
	string t;
	string p;
	//char t[256];
	//cin.getline(t, 256);
	getline(cin, t);
	getline(cin, p);
	auto ans = kmp(t, p);
	int ans_1 = ans.size();
	cout << ans_1 << '\n';
	for (int i = 0; i < ans_1; i++) {
		cout << ans[i] + 1 << '\n';
	}
	return 0;
}