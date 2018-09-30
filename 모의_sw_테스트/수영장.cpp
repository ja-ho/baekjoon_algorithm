#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	//freopen("C:\\Users\\magic\\jaeho\\Project1\\Project1\\baekjoon_algorithm\\모의_sw_테스트\\input.txt", "r", stdin);

	int t;
	int tn = 1;
	cin >> t;
	while (t--) {
		int ans = 0;
		int day, month, three, year;
		int plan[13];
		int d[13];
		cin >> day >> month >> three >> year;

		for (int i = 1; i <= 12; i++) {
			cin >> plan[i];
		}

		d[0] = 0;
		for (int i = 1; i <= 12; i++) {
			if (plan[i] * day < month) {
				d[i] = plan[i] * day;
			}
			else d[i] = month;
		}
		
		d[2] += d[1];

		for (int i = 3; i <= 12; i++) {
			d[i] = min(d[i - 1] + d[i], d[i - 3] + three);
		}

		if (d[12] > year) ans = year;
		else ans = d[12];

		cout << "#" << tn << ' ' << ans << '\n';
		tn++;
	}

	return 0;
}