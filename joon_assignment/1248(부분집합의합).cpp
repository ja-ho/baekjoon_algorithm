#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> tot_set;
int cnt;
void go(int idx, int now)
{
	if (idx >= n) return;
	if (now + tot_set[idx] == s) {
		cnt++;
		return;
	}
	go(idx + 1, now);
	go(idx + 1, now + tot_set[idx]);
	return;
}


int main(){
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		tot_set.push_back(temp);
	}
	go(0, 0);
	cout << cnt << '\n';

	return 0;
}