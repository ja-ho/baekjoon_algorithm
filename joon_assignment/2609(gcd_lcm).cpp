#include <iostream>
using namespace std;

#define max(a, b)	(((a) > (b)) ? (a) : (b))

int gcd(int a, int b) 
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}


int main() {
	int a, b;
	cin >> a >> b;
	int gcd_num = gcd(a, b);
	int lcm_num = a * b / gcd_num;
	cout << gcd_num << '\n';
	cout << lcm_num << '\n';
	return 0;
}