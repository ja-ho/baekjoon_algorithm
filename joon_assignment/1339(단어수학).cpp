#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int alpha_score[26];

int calc(vector<char> alpha, vector<string>st, vector<int> score)
{
	int sum = 0;

	for (int i = 0; i < alpha.size(); i++) {
		alpha_score[alpha[i] - 65] = score[i];
	}
	int st_size = st.size();
	for (int i = 0; i < st_size; i++) {
		int tmp_sum = 0;
		int st_i_length = st[i].length();
		for (int k = 0; k < st_i_length; k++) {
			if (k == st[i].length() - 1) tmp_sum += alpha_score[st[i][k] - 65];
			else {
				tmp_sum += alpha_score[st[i][k] - 65];
				tmp_sum *= 10;
			}
		}
		sum += tmp_sum;
	}
	return sum;
}

int main() {
	vector<char> alphabet;
	vector<string> str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
		for (int k = 0; k < tmp.length(); k++) {
			if (alphabet.size() == 0) {
				alphabet.push_back(tmp[k]);
				continue;
			}
			bool unique = true;
			for (int j = 0; j < alphabet.size(); j++) {
				if (alphabet[j] == tmp[k]) {
					unique = false;
				}
			}
			if (unique) alphabet.push_back(tmp[k]);
		}
	}

	sort(alphabet.begin(), alphabet.end());
	int num = 9;
	vector<int> score;
	for (int i = 0; i < alphabet.size(); i++) {
		score.push_back(num--);
	}
	sort(score.begin(), score.end());
	int answer = 0;
	do {
		int now = calc(alphabet, str, score);
		if (answer < now) answer = now;
	} while (next_permutation(score.begin(), score.end()));

	cout << answer << '\n';
	return 0;
}

