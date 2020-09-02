// 조건
// - 프로그래머스 지문을 참고하세요.
//접근
// - 단순 시뮬레이션으로 주어진 테이블에 대해 후보키로 사용가능한 속성을 구하는 문제
// - 1. 테이블의 각 속성의 모든 튜플이 중복되지 않을 때 후보키로 선정
// - 2. 1에서 선택된 속성을 제외한 뒤 나머지 속성에 대해 조합을 이루어 다시 1번 과정을 거침
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <set>
//
//using namespace std;
//vector<string> combination;
//
////조합에따른 후보키 판단 함수
//bool subset(vector<vector<string>> relation, string comb) {
//	set<string> candidate_check;
//	for (int r = 0; r < relation.size(); r++) {
//		//후보키 조합에 따른 string 합침
//		string temp = "";
//		for (int i = 0; i < comb.length(); i++) {
//			int c = comb[i] - '0';
//			temp += relation[r][c] + " ";
//		}
//
//		//만약 이미 있었다면 후보키가 될수없다고 반환
//		if (!candidate_check.insert(temp).second)    return false;
//	}
//	//끝까지 중복이 없었다면 최소성과 유일성을 만족시켰다. true 리턴
//	return true;
//}
//bool compare_str(string a, string b) {
//	if (a.length() != b.length())     
//		return a.length() < b.length();
//	return a < b;
//}
//
//void set_combination(int k, string temp, int max)
//{
//	for (int i = k; i < max; i++)
//	{
//		temp += to_string(i);
//		combination.push_back(temp);
//		set_combination(i+1,temp,max);
//		//LIFO, 앞서 vector에 넣은 부분을 제거하여 다음 조합을 만들 수 있도록 해준다
//		temp = temp.substr(0, temp.length() - 1);
//	}
//}
//int solution(vector<vector<string>> relation) {
//	int answer = 0;
//	//1. 조합을 생성
//	set_combination(0, "", relation[0].size());
//	sort(combination.begin(), combination.end(),compare_str);
//
//	for (int i = 0; i < combination.size(); i++)
//	{
//		if (subset(relation, combination[i]))
//		{
//			string temp = combination[i];
//			//후보키와 겹치는 조합은 다 없앤다. 13조합이면 1과 3이들어간것을 모두찾아서 제거
//			for (int j = combination.size() - 1; j >= i; j--) {
//				bool check = true;
//				for (auto t : temp) {
//					if (combination[j].find(t) == string::npos) {
//						check = false;
//						break;
//					}
//				}
//				//check가 존재하면 
//				if (check)    
//					combination.erase(combination.begin() + j);
//			}
//			//combination에서 원소를 제거를 했으므로 i를 감소하고 후보키였으므로 answer증가
//			i--;    answer++;
//		}
//	}
//	return answer;
//}
//
//void print(vector<vector<string>> relation, int answer) {
//	int t = solution(relation);
//	if (answer == t)
//		cout << "정답" << endl;
//	else
//		cout << "틀림" << endl;
//}
//
//int main() {
//	print({ {"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"},
//		{"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"},
//		{"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"} }, 2);
//	return 0;
//}