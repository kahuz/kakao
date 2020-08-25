//
// 조건
// - 가상의 닉네임을 사용하는 오픈채팅방을 개설
// - 각 유저는 id와 name 으로 구분된다
// - 유저의 name은 중복이 허용된다
// - 유저는 이름을 바꿀 수 있으며, 아래와 같은 방법으로 바꿀 수 있다
//  -> 채팅방을 나간 후, 새로운 닉네임으로 다시 들어온다
//  -> 채팅방에서 닉네임을 변경한다
// - 유저가 들어오고 나갈때에 대한 메세지가 채팅방에 출력된다
// - 유저가 닉네임을 변경했을 때, 채팅방에 표시되어 있는 메세지를 갱신하도록 해라
//
// 입력
// - 채팅방의 입출입과 닉네임 변경 기록이 담긴 문자열 record가 주어진다
// - record는 문자열이 담긴 배열이다 ( 1<= record <= 100,000)
// - record의 각 문자열은 "Action ID Name" 으로 구성되어 있으며, 공백으로 구분된다
// - Action은 Enter, Leave, Change로 구성되어 있다
// - Name은 알파벳으로 구성되며 대소문자를 구분한다
//
// 접근
// - 단순 시뮬레이션으로 map 을 이용해 들어온 id를 의 name을 설정해준 뒤 ( loop1 ) , 출력에 대해 map값을 확인하여 결정해준다 ( loop2 )
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string>::iterator input_iter = record.begin();
	vector<pair<string, string>> out_str;
	map<string, string> id_map;

	while (input_iter != record.end())
	{
		string::iterator it_b, it_e;
		it_b = input_iter->begin();
		it_b = find_if(it_b, input_iter->end(), not_space);
		it_e = find_if(it_b, input_iter->end(), space);
		string action(it_b, it_e);

		it_b = it_e;

		it_b = find_if(it_b, input_iter->end(), not_space);
		it_e = find_if(it_b, input_iter->end(), space);
		string id(it_b, it_e);
		it_b = it_e;

		if (action != "Change")
		{
			out_str.push_back(make_pair(action, id));
		}

		if (action == "Enter" || action == "Change")
		{
			it_b = find_if(it_b, input_iter->end(), not_space);
			it_e = find_if(it_b, input_iter->end(), space);
			string name(it_b, it_e);

			if (id_map.find(id) != id_map.end())
				id_map.erase(id);

			id_map.insert(make_pair(id, name));
		}
		input_iter++;
	}

	vector<pair<string, string>>::iterator out_iter = out_str.begin();

	while (out_iter != out_str.end())
	{
		string action = out_iter->first;
		string name = id_map[out_iter->second];

		if (action == "Enter")
		{
			answer.push_back(name +"님이 들어왔습니다.");
		}
		else if (action == "Leave")
		{
			answer.push_back(name + "님이 나갔습니다.");
		}
		out_iter++;
	}
	return answer;
}

int main(void)
{
	vector<string> record;

	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");

	solution(record);
	return 0;
}