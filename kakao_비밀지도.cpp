//
// 조건
// - 비상금을 숨겨놓은 장소를 기록한 비밀지도를 해독해야함
// - 비밀지도는 숫자로 암호화 되어 있기에 위치를 확인하기 위해서는 암호를 해독해야함
// - 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 공백 또는 벽(#)으로 이루어져 있다
// - 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다
// - * 각각 지도 1과 지도 2라고 하자, 지도 1또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다
// - * 지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다
//	-> 즉, 모두 공백일 때만 공백 나머지는 벽
// - 지도 1과 지도 2는 각각 정수 배열로 암호화 되어있다
// - 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1 공백 부분을 0으로 부호화했을때 얻어지는 이진수에 해당하는 값의 배열이다.
// - 각 지도의 암호를 해독하여 전체 지도를 얻어내자
//
// 입력
// - 지도의 한 변의 크기인 n ( 1<= n <= 16 )
// - 지도 1과 지도 2를 나타내는 정수배열 arr1, arr2
// - 정수 배열의 각 원소 x를 이진수로 변환했을때 길이는 n 이하이다.
//
// 접근
// - 단순 시뮬레이션 접근
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        int map_one = arr1[i];
        int map_two = arr2[i];
        vector<string> line_v;

        for (int j = 0; j < n; j++)
        {
            int tmp_one = map_one % 2;
            int tmp_two = map_two % 2;

            if (tmp_one || tmp_two)
                line_v.push_back("#");
            else
                line_v.push_back(" ");
            map_one /= 2;
            map_two /= 2;
        }

        string line;
        while (!line_v.empty())
        {
            line.append(line_v.back());
            line_v.pop_back();
        }
        answer.push_back(line);
    }

    return answer;
}

int main(void)
{

    int n = 5;
    vector<int> arr1;
    vector<int> arr2;

    arr1.push_back(9);
    arr1.push_back(20);
    arr1.push_back(28);
    arr1.push_back(18);
    arr1.push_back(11);

    arr2.push_back(30);
    arr2.push_back(1);
    arr2.push_back(21);
    arr2.push_back(17);
    arr2.push_back(28);

    solution(n, arr1, arr2);
    return 0;
}