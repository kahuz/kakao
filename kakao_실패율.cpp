//
// 조건
// - 실패율을 구하는 문제
// - 실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어 수 / 스테이지에 도달한 플레이어 수
// - 전체 스테이지 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지 번호가 담긴 stages 배열이 주어질때
//   실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담긴 배열을 return하라
//
// 입력
// - 스테이지 수 N 과 사용자가 멈춰있는 스테이지 번호 배열 stages가 주어짐
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int N, vector<int> stages) {
//    vector<int> answer;
//    vector<pair<int,float>> f_rate_v;
//    int prev_failer = 0;
//    int people = stages.size();
//
//    for (int i = 1; i <= N; i++)
//    {
//        int fail_n = 0;
//        for (int j = 0; j < people; j++)
//        {
//            if (stages[j] == i)
//                fail_n++;
//        }
//        float f_rate = fail_n / (float)(people - prev_failer);
//        f_rate_v.push_back(make_pair(i,f_rate));
//        prev_failer += fail_n;
//    }
//    
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N - i - 1; j++)
//        {
//            if (f_rate_v[j].second < f_rate_v[j + 1].second)
//            {
//                pair<int, float> tmp = f_rate_v[j+1];
//                f_rate_v[j + 1] = f_rate_v[j];
//                f_rate_v[j] = tmp;
//            }
//        }
//    }
//
//    for (int i = 0; i < N; i++)
//    {
//        answer.push_back(f_rate_v[i].first);
//    }
//    return answer;
//}
//
//int main(void)
//{
//    int N1 = 5;
//    vector<int> stages1;
//    int N2 = 4;
//    vector<int> stages2;
//
//    stages1.push_back(2);
//    stages1.push_back(1);
//    stages1.push_back(2);
//    stages1.push_back(6);
//    stages1.push_back(2);
//    stages1.push_back(4);
//    stages1.push_back(3);
//    stages1.push_back(3);
//
//    stages2.push_back(4);
//    stages2.push_back(4);
//    stages2.push_back(4);
//    stages2.push_back(4);
//    stages2.push_back(4);
//
//    solution(N1, stages1);
//    solution(N2, stages2);
//
//    return 0;
//}