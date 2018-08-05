#include <iostream>
#include <cmath>
using namespace std;

int a[501];

double calc_mean(int start, int k)
{
	double sum = 0;
	for (int i = start; i < start + k; i++) {
		sum += a[i];
	}
	return sum / (double)k;
}

double calc_variance(int start, int k, double mean)
{
	double sum = 0;
	for (int i = start; i < start + k; i++) {
		sum += pow((a[i] - mean), 2);
	}
	return (sum / (double)k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double ans = 1000000000;

	for (int j = k; j <= n; j++) {
		for (int i = 0; i <= n - j; i++) {
			double temp_mean = calc_mean(i, j);
			double temp_variance = calc_variance(i, j, temp_mean);
			double temp_std_diviation = sqrt(temp_variance);
			if (temp_std_diviation < ans) ans = temp_std_diviation;
		}
	}
	cout << fixed;
	cout.precision(11);
	cout << ans << '\n';
	return 0;
}