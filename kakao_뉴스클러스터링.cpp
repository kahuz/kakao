// 시작 2:45
// 조건
// - 주어진 두 문자열에 대해 자카드 유사도를 구하도록 한다.
// - 주어진 조건이 복잡하므로 프로그래머스 지문을 참고하도록 하자.
//
#include <string>
#include <vector>
using namespace std;

#define SLICE_N 2
#define SIMILAR_N 65536

char trans_char(char input)
{
	char res;

	if (input >= 'a' && input <= 'z')
	{
		res = input;
	}
	else if (input >= 'A' && input <= 'Z')
	{
		char tmp = input + 0x20;
		res = tmp;
	}
	else
		res = false;

	return res;
}
int solution(string str1, string str2) {
	int answer = 0;
	float res = 0.0;

	vector<string> str1_v, str2_v;

	for (int i = 0; i < str1.size(); i++)
	{
		string tmp = str1.substr(i, SLICE_N);

		if (tmp.size() == SLICE_N)
		{
			char tmp1 = trans_char(tmp[0]);
			char tmp2 = trans_char(tmp[1]);

			if (tmp1 && tmp2)
			{
				string trans_str;
				trans_str.push_back(tmp1);
				trans_str.push_back(tmp2);
				str1_v.push_back(trans_str);
			}
		}
	}

	for (int i = 0; i < str2.size(); i++)
	{
		string tmp = str2.substr(i, SLICE_N);

		if (tmp.size() == SLICE_N)
		{
			char tmp1 = trans_char(tmp[0]);
			char tmp2 = trans_char(tmp[1]);

			if (tmp1 && tmp2)
			{
				string trans_str;
				trans_str.push_back(tmp1);
				trans_str.push_back(tmp2);
				str2_v.push_back(trans_str);
			}
		}
	}

	float AnB = 0;
	float AuB = 0;

	if (str1_v.size() == 0 && str2_v.size() == 0)
		return 1 * SIMILAR_N;
	else
	{
		//int for_len = str1_v.size() <= str2_v.size() ? str1_v.size() : str2_v.size();

		if (str1_v.size() == str2_v.size())
		{
			for (int i = 0; i < str1_v.size(); i++)
			{
				for (int j = 0; j < str2_v.size(); j++)
				{
					if (str1_v[i] == str2_v[j])
					{
						str2_v[j] = "";
						AnB++;
						break;
					}
				}
			}

			AuB = str1_v.size() + str2_v.size() - AnB;
		}
		else if (str1_v.size() > str2_v.size())
		{
			for (int i = 0; i < str2_v.size(); i++)
			{
				for (int j = 0; j < str1_v.size(); j++)
				{
					if (str2_v[i] == str1_v[j])
					{
						str1_v[j] = "";
						AnB++;
						break;
					}
				}
			}
			AuB = str1_v.size() + str2_v.size() - AnB;
		}
		else if (str1_v.size() < str2_v.size())
		{
			for (int i = 0; i < str1_v.size(); i++)
			{
				for (int j = 0; j < str2_v.size(); j++)
				{
					if (str1_v[i] == str2_v[j])
					{
						str2_v[j] = "";
						AnB++;
						break;
					}
				}
			}
			AuB = str1_v.size() + str2_v.size() - AnB;
		}
	}
	res = (float)(AnB / AuB * SIMILAR_N);
	answer = res;
	return answer;
}

int main(void)
{
	vector<pair<string, string>> input;

	input.push_back(make_pair("    ", "french"));
	input.push_back(make_pair("a b c", "french"));
	//input.push_back(make_pair("FRANCE", "french"));
	//input.push_back(make_pair("FRANCE", "french"));
	//input.push_back(make_pair("handshake", "shake hands"));
	//input.push_back(make_pair("aa1+aa2", "AAAA12"));
	//input.push_back(make_pair("E=M*C^2", "e=m*c^2"));

	vector<pair<string, string>>::iterator input_iter = input.begin();

	while (input_iter != input.end())
	{
		solution(input_iter->first, input_iter->second);
	
		input_iter++;
	}
	return 0;
}