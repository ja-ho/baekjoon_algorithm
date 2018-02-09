#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		int M;
		bool over = false;
		vector<long long> v;
		cin >> M;
		for (int i = 0; i < M; i++) {
			long long temp;
			cin >> temp;
			v.push_back(temp);
		}
		int d = v[1] - v[0];
		for (int i = 0; i <= d; i++) {
			over = false;
			for (int j = 0; j < v.size() - 1; j++) {
				if (v[j + 1] - v[j] != i) {
					over = true;
					break;
				}
			}
			if (!over) {
				Answer++;
			}
		}


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}