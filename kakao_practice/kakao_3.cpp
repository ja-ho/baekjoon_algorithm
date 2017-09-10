#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	//vector<vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
	cout << v[0][0] << " ";
	int x, y;
	vector<int> ans;

	if (v[1][0] == v[2][0]) {
		x = v[0][0];
	}
	else if (v[0][0] == v[1][0]) {
		x = v[2][0];
	}
	else {
		x = v[1][0];
	}

	if (v[1][1] == v[2][1]) {
		y = v[0][1];
	}
	else if (v[0][1] == v[1][1]) {
		y = v[2][1];
	}
	else {
		y = v[1][1];
	}
	ans.push_back(x);
	ans.push_back(y);
	return ans;
}