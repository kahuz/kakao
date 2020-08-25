// 10:50
// ����
// - �־��� ���ڿ��� n�� ������ �߶� ǥ�������� ���� ª�� ǥ���Ǵ� ��츦 ã�ƶ�
// - ���ڿ��� �ڸ��� �׻� ���� ���̷θ� �߶���Ѵ�
// - ���α׷��ӽ� ���� ������ Ȯ�����ּ���
//
// �Է�
// - ������ ���ڿ� s�� �־����� ( 1<= s <= 1,000)
// - s�� �ҹ��ڷθ� �̷�����ִ�
//
// ����
// - �ܼ� �ùķ��̼�. 
// - slice�� ũ��� �ִ� input str size / 2����, s_len/2���� Ŭ ��� �ᱹ slice ������ 2�� �ǹǷ� �˻��� �ǹ̰� ����
// - slice�� �ϴ� ������, slice�� ���ڿ��� ���� ���ӵ� ���ڿ��� ó�� �� �������� ����
// - �׽�Ʈ���̽� 5���� �����ٸ� �Է� s�� ���̰� 1�� ����̴� �̿� ���� ó���� Ȯ���غ� ��
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 93485438;
	int s_len = s.size();
	string::iterator s_it_b, s_it_e;
	if (s.size() < 2)
		return s.size();
	for (int slice = 1; slice <= s_len / 2; slice++)
	{
		string res;
		string slice_str = "";
		int equl_len = 1;

		for (int i = 0; i < s.size();)
		{
			string tmp = s.substr(i, slice);

			if (slice_str == tmp)
				equl_len++;
			else
			{
				if (equl_len > 1)
					res.append(to_string(equl_len) + slice_str);
				else
					res.append(slice_str);
				slice_str = tmp;
				equl_len = 1;
			}

			i += slice;
		}

		if (equl_len > 1)
			res.append(to_string(equl_len) + slice_str);
		else
			res.append(slice_str);

		if (answer > res.size())
			answer = res.size();
	}

	return answer;
}
int main(void)
{
	vector<string> input;

	input.push_back("aabbaccc");
	input.push_back("ababcdcdababcdcd");
	input.push_back("abcabcdede");
	input.push_back("abcabcabcabcdededededede");
	input.push_back("xababcdcdababcdcd");
	input.push_back("a");
	input.push_back("aa");
	input.push_back("ab");
	input.push_back("abcd");

	vector<string>::iterator input_it = input.begin();

	while (input_it != input.end())
	{
		string str(input_it->begin(), input_it->end());
		solution(str);
		input_it++;
	}
	return 0;
}