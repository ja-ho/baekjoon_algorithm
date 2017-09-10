#include<vector>
#include <algorithm>
using namespace std;

bool solution(vector<int> arr)
{
	bool answer = true;
	sort(arr.begin(), arr.end());
	int length = arr.size();
	for (int i = 0; i< length; i++) {
		if (arr[i] != i + 1) {
			return false;
		}
	}

	return answer;
}