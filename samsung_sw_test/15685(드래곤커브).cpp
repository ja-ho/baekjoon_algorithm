#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//0: ->(x++), 1: 위(y--), 2: <-(x--), 3: 아래(y++) 

struct point {
	int x, y;
	point() : x(0), y(0) {
	};
	point(int x, int y) : x(x), y(y) {

	};
	bool operator <(const point& pt) const
	{
		if (x == pt.x) {
			return y < pt.y;
		}
		else return x < pt.x;
		//return (x < pt.x) || ((!(pt.x < x)) && (y < pt.y));
	}	//set으로 사용가능. set은 sorted되어야 하고 unique한 두 가지 특성
};

class dragon_curve {
public:
	point p;
	int d, g;
	dragon_curve() : p(), d(0), g(0) {
	};
	dragon_curve(int x, int y, int d, int g) : p(x, y), d(d), g(g) {
	};

}; 

//struct cmpPoint {
//	bool operator()(const point& lp, const point& rp) const
//	{
//		return (lp.x < rp.x) || ((!(rp.x < lp.x)) && (lp.y < rp.y));
//	};
//};  --> set<point, cmpPoint> set;

//bool operator <(const point& lhs, const point &rhs)
//{
//	return (lhs.x < rhs.x) || ((!(rhs.x < lhs.x)) && (lhs.y < rhs.y));
//} -> global free function

int power_of_two(int g)
{
	return (1 << g);
}

void go(point start, int d, int g, set<point>& points)
{
	stack<int> st;
	stack<int> st1;
	st.push(d);
	st1.push(d);
	for (int i = 0; i < g; i++) {
		while (!st.empty()) {
			int dir = st.top();
			st.pop();
			int nd = (dir + 1) % 4;
			st1.push(nd);
		}
		st = st1;
	}
	stack<int> st2;
	while (!st1.empty()) {
		st2.push(st1.top());
		st1.pop();
	}
	point temp = start;
	while (!st2.empty()) {
		int d = st2.top();
		st2.pop();
		if (d == 0) {
			temp.x++;
		}
		else if (d == 1) {
			temp.y--;
		}
		else if (d == 2) {
			temp.x--;
		}
		else if (d == 3) {
			temp.y++;
		}
		else {
			cout << "what the fuck?" << '\n';
		}
		points.insert(temp);
	}
}

int check_point(set<point>& points)
{
	int ans = 0;
	set<point>::iterator it;
	for (it = points.begin(); it != points.end(); it++) {
		if (points.find(point((it->x) + 1, (it->y))) == points.end()) {
			continue;
		}
		if (points.find(point((it->x), (it->y) + 1)) == points.end()) {
			continue;
		}
		if (points.find(point((it->x) + 1, (it->y) + 1)) == points.end()) {
			continue;
		}
		ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<dragon_curve> command;
	set<point> points;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		command.push_back(dragon_curve(x, y, d, g));
		points.insert(point(x, y));
	}
	for (int i = 0; i < command.size(); i++) {
		go(command[i].p, command[i].d, command[i].g, points);
	}

	int ans = check_point(points);

	cout << ans << '\n';
	return 0;
}