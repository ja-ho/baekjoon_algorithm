#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> numbers;

int X;
int Answer;
int length;				//number_length;
int minimum_count;

//void prime_factorization(int i)
//{
//	if (i < 1) return;
//	int p = 2;
//	while (i != 1) {
//		if (i%p == 0) {
//			prime_factor[p]++;
//			i /= p;
//		}
//		else {
//			p++;
//		}
//	}
//}

int calculate_devisor(int n, vector<int> &divide_number)
{
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			if (i != 1) {
				divide_number.push_back(i);		//1ÀÌ¸é ½ºÅµ
			}
			if (i != n / i) {
				divide_number.push_back(n / i);
			}
		}
	}

	sort(divide_number.begin(), divide_number.end());
	return divide_number.size();
}

int is_possible(int n)
{
	int temp;
	bool possible;
	int number_length = 0;
	while (n != 0) {
		possible = false;
		temp = n % 10;
		n /= 10;
		for (int i = 0; i < length; i++) {
			if (temp == numbers[i]) {
				possible = true;
				number_length++;
				break;
			}
		}
		if (!possible) return 0;
	}
	return number_length;
}



void go(int n, int button_count)
{
	int number_length;
	int temp_count;
	vector<int> temp_divided_number;
	if (n == 1) {
		if (button_count < minimum_count) {
			minimum_count = button_count;
		}
		return;
	}
	int divide_length = calculate_devisor(n, temp_divided_number);

	for (int i = divide_length - 1; i >= 0; i--) {
		temp_count = button_count;
		if (number_length = is_possible(temp_divided_number[i])) {
			temp_count += number_length;
			temp_count++;
			go(n / temp_divided_number[i], temp_count);
		}
	}
}

int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		length = 0;
		minimum_count = 1000000;
		numbers.clear();
		for (int i = 0; i < 10; i++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				numbers.push_back(i);
				length++;
			}
		}
		cin >> X;

		if (X == 1) {
			if (is_possible(X)) {
				Answer = 2;
			}
		}
		else {
			go(X, 0);
			if (minimum_count == 1000000) Answer = -1;
			else Answer = minimum_count;
		}
		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}