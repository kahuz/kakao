// 10:50
// 조건
// - 주어진 문자열을 n개 단위로 잘라 표현했을때 가장 짧게 표현되는 경우를 찾아라
// - 문자열을 자를때 항상 같은 길이로만 잘라야한다
// - 프로그래머스 문제 지문을 확인해주세요
//
// 입력
// - 압축할 문자열 s가 주어진다 ( 1<= s <= 1,000)
// - s는 소문자로만 이루어져있다
//
// 접근
// - 단순 시뮬레이션. 
// - slice의 크기는 최대 input str size / 2까지, s_len/2보다 클 경우 결국 slice 단위가 2로 되므로 검사할 의미가 없다
// - slice를 하는 과정과, slice된 문자열에 대해 연속된 문자열의 처리 두 과정으로 진행
// - 테스트케이스 5에서 막힌다면 입력 s의 길이가 1인 경우이니 이에 대한 처리를 확인해볼 것
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