//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool alphabet[26];
//
//int alpha;
//vector<string> words;
//int k_5;
//
//int count()
//{
//	int cnt = 0;
//	for (string word : words) {
//		bool ok = true;
//		for (char x : word) {
//			if (!alphabet[x - 'a']) {
//				ok = false;
//				break;
//			}
//		}
//		if (ok) cnt++;
//	}
//	return cnt;
//}
//
//
//int go(int idx, int k)
//{
//	int answer = 0;
//	if (k < 0) return 0;
//	if (idx == 26) return count();
//	if (idx == 0 || idx == 2 || idx == 8 || idx == 13 || idx == 19) {
//		int temp = go(idx + 1, k);
//		if (temp > answer) answer = temp;
//	}
//	else {
//		alphabet[idx] = true;
//		int temp = go(idx + 1, k - 1);
//		alphabet[idx] = false;
//		if (answer < temp) answer = temp;
//		temp = go(idx + 1, k);
//		if (answer < temp) answer = temp;
//	}
//	return answer;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n, k;
//	string word;
//	cin >> n >> k;
//
//	for (int i = 0; i < n; i++) {
//		cin >> word;
//		words.push_back(word);
//	}
//
//	if (k < 5) cout << 0 << '\n';
//	else {
//		k_5 = k - 5;
//		alphabet[0] = true;
//		alphabet[2] = true;
//		alphabet[8] = true;
//		alphabet[13] = true;
//		alphabet[19] = true;
//		int answer = go(0, k_5);
//
//		cout << answer << '\n';
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> words;

int count(int mask)
{
	int cnt = 0;
	for (int word : words) {
		if (!(word & (1 << 26) - 1 - mask)) {
			cnt++;
		}
	}
	return cnt;
}

int go(int idx, int k, int mask)
{
	int ans = 0;
	if (k < 0) return 0;
	if (idx == 26) return count(mask);
	if (idx == 0 || idx == 2 || idx == 8 || idx == 13 || idx == 19) {
		int temp = go(idx + 1, k, mask);
		if (temp > ans) ans = temp;
	}
	else {
		int temp = go(idx + 1, k - 1, mask | (1 << idx));
		if (ans < temp) ans = temp;
		temp = go(idx + 1, k, mask);
		if (ans < temp) ans = temp;
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	string word;
	cin >> n >> k;
	words.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> word;
		for (char x : word) {
			words[i] |= (1 << (x - 'a'));
		}
	}

	if (k < 5) cout << 0 << '\n';
	else {
		int alphabet = 0;
		alphabet |= (1 << 0);
		alphabet |= (1 << 2);
		alphabet |= (1 << 8);
		alphabet |= (1 << 13);
		alphabet |= (1 << 19);
		int ans = go(0, k - 5, alphabet);
		cout << ans << '\n';
	}
	return 0;
}