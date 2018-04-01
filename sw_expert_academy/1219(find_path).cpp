#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int Answer;
vector<vector<int>> path;
bool visit[100];

bool go()
{
	queue<int> q;
	q.push(0);
	bool is_possible = false;
	while (!q.empty()) {
		int current_pos = q.front();
		q.pop();

		if (current_pos == 99) {
			is_possible = true;
			break;
		}

		if (visit[current_pos] == true) {
			continue;
		}
		visit[current_pos] = true;

		for (int i = 0; i < path[current_pos].size(); i++) {
			q.push(path[current_pos][i]);
		}
	}
	return is_possible;
}


int main()
{
	freopen("input.txt", "r", stdin);
	int T, num_path;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> T >> num_path;
		path.clear();
		path.resize(100);

		for (int i = 0; i < num_path; i++) {
			int n, m;
			cin >> n >> m;
			path[n].push_back(m);
		}

		fill(&visit[0], &visit[100], false);
		if (go()) {
			Answer = 1;
		}
		else {
			Answer = 0;
		}
		cout << "#" << T << " " << Answer << endl;
	}
	return 0;
}