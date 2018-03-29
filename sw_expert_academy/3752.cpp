#include <iostream>
#include <vector>
#include <set>
using namespace std;

int Answer;
int T, N;
vector<int> scores;
set<int> possible_score;


int go()
{
	for (int i = 0; i <= N; i++) {
		if (i == 0) {
			possible_score.insert(0);
		}
		
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		scores.clear();
		for (int i = 0; i < N; i++) {
			int score;
			cin >> score;
			scores.push_back(score);
		}

		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}