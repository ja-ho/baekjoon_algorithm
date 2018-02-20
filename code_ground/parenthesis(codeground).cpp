//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//using namespace std;
//
//int Answer;
//string str;
//
//int find_length()
//{
//	stack<char> st;
//	int length = str.length();
//	int i = 0;
//	int cnt = 0;
//
//	for (int i = 0; i < length; i++) {
//		
//	}
//
//
//	return cnt;
//}
//
//
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		Answer = 0;
//		str.clear();
//		cin >> str;
//
//		Answer = find_length();
//
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;
//}

#include <stdio.h>
#include <vector>
#include <memory.h>
#include <string>
#include <iostream>

using namespace std;

vector <char> stk;




/*bool match(char x, char y) {
if (x == '(' && y == ')') return true;
if (x == '{' && y == '}') return true;
if (x == '[' && y == ']') return true;
return false;
}
*/

int main() {

	int T, test_case;
	int i, j, k, cnt;
	int a, b;
	int res;
	int sum = 0;


	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		res = 0;
		sum = 0;

		stk.clear();

		string input;
		cin >> input;
		//scanf("%s", &input);



		for (i = 0; i < input.size(); i++)
		{

			if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
				stk.push_back(input[i]);
				res++;
			}

			else
			{
				if (stk.size() != 0)
				{
					if (input[i] == ')')
					{
						if (stk.back() == '(')
						{
							//	res++;
							stk.pop_back();
						}
						else {
							res = 0;
							stk.clear();
						}
					}
					else if (input[i] == ']')
					{

						if (stk.back() == '[')
						{
							//	res++;
							stk.pop_back();
						}
						else {
							res = 0;
							stk.clear();
						}
					}
					else if (input[i] == '}')
					{
						if (stk.back() == '{')
						{
							//	res++;
							stk.pop_back();
						}
						else {
							res = 0;
							stk.clear();
						}
					}
				}
				else if (stk.size() == 0)
				{
					res = 0;
					stk.clear();
				}

				if (stk.size() == 0 && res>sum)
				{
					sum = res;
				}

			}

		}



		cout << "Case #" << test_case + 1 << endl;
		cout << sum * 2 << endl;


	}
	return 0;

}