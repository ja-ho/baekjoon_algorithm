#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;

typedef struct _point {
	double x;
	double y;
} point;

int n, q, hp;
vector<pair<pair<int, int>, int>> query;
vector<int> g(250001);
double calc_dist(double a, double b, double c, double d)
{
	double dist = (sqrt(pow((a - c), 2) + pow((b - d), 2)));
	return dist;
}

bool go(int x, int y, const point &end_point, double temp_hp, bool boost, string history)
{
	if (calc_dist(x, y, end_point.x, end_point.y) <= temp_hp)
	{
		return true;
	}
	if (calc_dist(x, y, x, end_point.y) <= temp_hp && boost == true) return true;
	if (calc_dist(x, y, end_point.x, y) <= temp_hp && boost == true) return true;
	int length = history.length();
	for (int i = 0; i < n; i++) {
		bool visit = false;
		for (int j = 0; j < length; j++) {
			if (history[j] + '0' == i) {
				visit = true;
				break;
			}
		}
		if (visit) continue;
		int temp_x = cp[i].first;
		int temp_y = cp[i].second;
		int dist = calc_dist(x, y, temp_x, temp_y);
		if (dist <= temp_hp) {
			go(temp_x, temp_y, end_point, hp, true, history + (char)i);
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	vector<pair<int, int>> cp(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		cp[i] = make_pair(x, y);
	}

	for (int i = 0; i < q; i++) {
		int a, b, hp;
		cin >> a >> b >> hp;
		query.push_back(make_pair(make_pair(a, b), hp));
	}



	return 0;
}