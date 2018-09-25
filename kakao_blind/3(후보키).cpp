#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> relation) {
	int answer = 0;

	int relation_size = relation.size();
	int column_size = relation[0].size();

	map<int, bool> Unique;

	for (int subset = 1; subset < (1 << column_size); subset++) {
		map<vector<string>, bool> hash;		//각 subset마다의 유일성 만족하는 것을 집어넣음.
		bool flag = true;

		for (int r = 0; r < relation_size; r++) {
			vector<string> row;
			for (int i = 0; i < column_size; i++) {
				if (subset & (1 << i)) {
					row.push_back(relation[r][i]);
				}
			}
			if (hash[row]) flag = false;
			else hash[row] = true;
		}

		if (flag) Unique[subset] = true;
		else continue;

		for (int i = 0; i < column_size; i++) {					//최소성 검사
			if (subset & (1 << i) && subset ^ (1 << i)) {
				int index = subset ^ (1 << i);
				if (Unique[index]) {
					flag = false;
				}
			}
		}
		if (flag) answer++;
	}
	return answer;
}


int main() {
	vector<vector<string>> relation = { {"100","ryan", "music","2"},{"200","apeach","math","2"},
	{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };
	int ans = solution(relation);
	cout << ans << '\n';
	return 0;
}