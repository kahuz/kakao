// 12:15
//
// 조건
// - 다트 게임은 다트판에 다트를 세 차례 던져 그 점수의 합계로 승부를 결정하는 게임
// - 다트 게임은 총 3번의 기회로 구성
// - 각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다
// - 점수와 함께 Single(S) Double(D) Triple(T) 영역이 존재하고, 각 영역 당첨시 점수에서 1,2,3 제곱으로 계산된다
// - 옵션으로 스타상(*) 아차상(#) 이 존재하며, 스타상 당첨시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다
// - 아차상 당첨시 해당 점수는 마이너스 된다
// - 스타상은 첫번째 기회에도 나올 수 있다. 이 경우 첫번째 스타상의 점수만 2배가 된다
// - 스타상의 효과는 다른 스타상의 효과와 중첩될 수 있다. 이 경우 중첩된 스타상의 점수는 2배가 된다
// - 스타상의 효과는 아차상의 효과와 중첩될 수 있다. 이 경우 아차상의 점수는 -2배가 된다
// - Single Double Triple은 점수마다 하나씩 존재한다
// - 스타상 아차상은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다.
// - 0~10의 정수와 문자 S D T * # 으로 구성된 문자열이 입력될 시 총 점수를 반환하는 함수를 만들어라
//
// 입력
// - 점수 | 보너스 | 옵션 으로 이루어진 문자열 3세트
// - ex) 1S2D*3T
//
// 접근
// - 단순 시뮬레이션, 점수 기준으로 split하여 처리

//#include <string>
//#include <queue>
//using namespace std;
//
//int solution(string dartResult) {
//    int answer = 0;
//    int score[3] = { 0 };
//    queue<string> dart_v;
//    
//    int start_idx = -1;
//
//    for (int i = 0; i < dartResult.size(); i++)
//    {
//        if (dartResult[i] >= '1' && dartResult[i] <= '9')
//        {
//            string dart(1, dartResult[i]);
//            dart_v.push(dart);
//
//            if (dartResult[i + 1] == '0')
//            {
//                dart_v.back() += dartResult[++i];
//            }
//        }
//        else if (dartResult[i] == '0')
//        {
//            dart_v.push("0");
//        }
//        else
//            dart_v.back() += dartResult[i];
//    }
//
//    for (int i = 0; i < 3; i++)
//    {
//        string score_line = dart_v.front();
//        int bonus_idx = 0;
//
//        dart_v.pop();
//        
//        if ((bonus_idx = score_line.find('S')) == string::npos)
//        {
//            if ((bonus_idx = score_line.find('D')) == string::npos)
//            {
//                bonus_idx = score_line.find('T');
//            }
//        }
//        int num = 0;
//        if (bonus_idx < 2)
//            num = score_line[bonus_idx - 1] - '0';
//        else
//            num = 10;
//        int square = 0;
//
//        switch (score_line[bonus_idx])
//        {
//        case 'S': score[i] = num;
//            break;
//        case 'D': score[i] = num * num;
//            break;
//        case 'T': score[i] = num * num * num;
//            break;
//        }
//
//        if (score_line.size() > bonus_idx+1)
//        {
//            if (score_line[bonus_idx+1] == '*')
//            {
//                if (i > 0)
//                {
//                    score[i - 1] = score[i - 1] * 2;
//                }
//                score[i] = score[i] * 2;
//
//            }
//            else if (score_line[bonus_idx+1] == '#')
//            {
//                score[i] = score[i] * -1;
//            }
//        }
//
//    }
//    for (int i = 0; i < 3; i++)
//        answer += score[i];
//
//    return answer;
//}
//
//int main(void)
//{
//    string q1 = "1S2D*3T";
//    string q2 = "1D2S#10S";
//    string q3 = "1D2S0T";
//    string q4 = "1S*2T*3S";
//    string q5 = "1D#2S*3S";
//    string q6 = "1T2D3D#";
//    string q7 = "1D2S3T*";
//
//    solution(q7);
//    return 0;
//}