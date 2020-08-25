//
// ����
// - ������ �г����� ����ϴ� ����ä�ù��� ����
// - �� ������ id�� name ���� ���еȴ�
// - ������ name�� �ߺ��� ���ȴ�
// - ������ �̸��� �ٲ� �� ������, �Ʒ��� ���� ������� �ٲ� �� �ִ�
//  -> ä�ù��� ���� ��, ���ο� �г������� �ٽ� ���´�
//  -> ä�ù濡�� �г����� �����Ѵ�
// - ������ ������ �������� ���� �޼����� ä�ù濡 ��µȴ�
// - ������ �г����� �������� ��, ä�ù濡 ǥ�õǾ� �ִ� �޼����� �����ϵ��� �ض�
//
// �Է�
// - ä�ù��� �����԰� �г��� ���� ����� ��� ���ڿ� record�� �־�����
// - record�� ���ڿ��� ��� �迭�̴� ( 1<= record <= 100,000)
// - record�� �� ���ڿ��� "Action ID Name" ���� �����Ǿ� ������, �������� ���еȴ�
// - Action�� Enter, Leave, Change�� �����Ǿ� �ִ�
// - Name�� ���ĺ����� �����Ǹ� ��ҹ��ڸ� �����Ѵ�
//
// ����
// - �ܼ� �ùķ��̼����� map �� �̿��� ���� id�� �� name�� �������� �� ( loop1 ) , ��¿� ���� map���� Ȯ���Ͽ� �������ش� ( loop2 )
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
			answer.push_back(name +"���� ���Խ��ϴ�.");
		}
		else if (action == "Leave")
		{
			answer.push_back(name + "���� �������ϴ�.");
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