#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	vector<pair<pair<int, int>, pair<int, int>>> line;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x1, y1, x2, y2;
			pair<int, int>line1, line2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			line1 = make_pair(2 * x1, 2 * y1);
			line2 = make_pair(2 * x2, 2 * y2);
			line.push_back(make_pair(line1, line2));
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}