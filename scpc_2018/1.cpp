#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int bus_cnt;
int Answer;
int N, K;

ll players[200001];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int start_num;
		Answer = 0;
		bus_cnt = 1;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> players[i];
		}

		sort(players, players + N);
		
		start_num = 0;
		for (int i = 1; i < N; i++) {
			int gap = players[i] - players[start_num];
			if (gap <= K) {
				bus_cnt++;
			}
			else {
				start_num++;
			}
		}

		Answer = bus_cnt;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}