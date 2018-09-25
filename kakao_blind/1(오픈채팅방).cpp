#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> map;
	vector<pair<string, char>> order;
	int record_length = record.size();
	for (int i = 0; i < record_length; i++) {
		int cnt = 0;
		string command = "";
		string uid = "";
		string nick = "";
		istringstream iss(record[i]);
		do {
			string temp;
			iss >> temp;
			if (cnt == 0) command = temp;
			if (cnt == 1) uid = temp;
			if (cnt == 2) nick = temp;
			cnt++;
		} while (iss);
		if (command[0] == 'E') {
			map[uid] = nick;
			order.push_back(make_pair(uid, 'E'));
		}
		else if (command[0] == 'L') {
			order.push_back(make_pair(uid, 'L'));
		}
		else if (command[0] == 'C') {
			map[uid] = nick;
		}
	}
	int order_size = order.size();

	for (int i = 0; i < order_size; i++) {
		string str = "";
		auto it = order[i];
		string nick = map[it.first];
		char command = it.second;
		str += nick;
		if (command == 'E') {
			str += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.\n";
		}
		else if (command == 'L') {
			str += "´ÔÀÌ ³ª°¬½À´Ï´Ù.\n";
		}
		answer.push_back(str);
	}
	return answer;
}

int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", 
		"Enter uid1234 Prodo", "Change uid4567 Ryan" };
	auto it = solution(record);

	for (int i = 0; i < it.size(); i++) {
		cout << it[i] << '\n';
	}


	return 0;
}


//if (cnt == 0) {
//	if (temp[0] == 'E') {
//
//	}
//	else if (temp[0] == 'L') {
//
//	}
//	else if (temp[0] == 'C') {
//
//	}
//}
//else if (cnt == 1) {
//
//}
//else if (cnt == 2) {
//
//}