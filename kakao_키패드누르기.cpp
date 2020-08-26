//
// 조건
// - 키패드에서 왼손과 오른손의 엄지손가락만을 이용해서 숫자만을 입력하려고 한다
// - 맨 처음 왼손 엄지손가락은 *, 오른손 엄지손가락은 #에 위치해있다
// - 엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며, 키패드 이동 한 칸은 거리 1에 해당한다
// - 왼쪽 열의 3개의 숫자 1 4 7 입력할 때는 왼손 엄지손가락을 사용한다
// - 오른쪽 열 3개의 숫자 3 6 9 를 입력할때는 오른손 엄지손가락을 사용한다
// - 가운데 열 4개의 숫자 2 5 8 0 을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용한다
//  -> 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손가락 왼손잡이는 왼손가락을 사용
// - 순서대로 누를 번호가 담긴 배열 numbers, 손잡이 방향 hand가 주어질때 각 번호를 누른 손이 어느 손인지 나타내는 연속된 문자열을 return하라
//
// 입력
// - 순서대로 누를 번호 numbers ( 1 <= numbers <= 1000 , 원소 : 0 ~ 9)
// - 손잡이를 나타내는 left와 right
//
// 출력
// - 왼손을 사용했을땐 L 오른손을 사용했을땐 R을 붙여준다
//
// 접근
// - 단순 시뮬레이션
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int>::iterator num;
    int cur_L = 10, cur_R = 10;
    string hand_d;

    if (hand == "left")
        hand_d = "L";
    else if (hand == "right")
        hand_d = "R";

    for (num = numbers.begin(); num != numbers.end(); num++)
    {
        if (*num == 1 || *num == 4 || *num == 7)
        {
            cur_L = *num;
            answer.append("L");
        }
        else if (*num == 3 || *num == 6 || *num == 9)
        {
            cur_R = *num - 2;
            answer.append("R");
        }
        else
        {
            queue<pair<int, int>> q;
            int key_pad[4][3] = { 0 };
            int dist_L = 0, dist_R = 0;
            if (*num == 0)
                *num = 11;

            int row_L, row_R, row = 0;
            int col_L, col_R, col = 0;

            row = (*num / 3 )- 1;
            col = (*num % 3 )- 1;
            key_pad[row][col] = 3;

            row_L = ( cur_L / 3 ) -1;
            row_R = ( cur_R / 3 ) -1;
            col_L = ( cur_L % 3 ) - 1;
            col_R = ( cur_R % 3 ) - 1;

            key_pad[row_L][col_L] = 1;
            key_pad[row_R][col_R] = 2;

            q.push(make_pair(col_L, row_L));
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();
                
                if (key_pad[y][x] == 3)
                {
                    while (!q.empty())
                        q.pop();

                    break;
                }
                key_pad[y][x] == 1;
                for (int i = 0; i < 4; i++)
                {
                    int xn = x + dx[i];
                    int yn = y + dy[i];

                    if (xn < 0 || xn >= 3 || yn < 0 || yn >= 4)  continue;

                    if (key_pad[yn][xn] != 1)
                    {
                        dist_L++;
                        q.push(make_pair(xn, yn));
                    }
                }

                q.push(make_pair(col_R, row_R));
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;

                    q.pop();

                    if (key_pad[y][x] == 3)
                    {
                        while (!q.empty())
                            q.pop();

                        break;
                    }
                    key_pad[y][x] == 2;

                    for (int i = 0; i < 4; i++)
                    {
                        int xn = x + dx[i];
                        int yn = y + dy[i];

                        if (xn < 0 || xn >= 3 || yn < 0 || yn >= 4)  continue;

                        if (key_pad[yn][xn] != 2)
                        {
                            dist_R++;
                            q.push(make_pair(xn, yn));
                        }
                    }
                }
            }

            if (dist_L < dist_R)
            {
                cur_L = *num;
                answer.append("L");
            }
            else if(dist_R < dist_L)
            {
                if (cur_R == 2 || cur_R == 5 || cur_R == 8 || cur_R == 11)
                    cur_R = *num;
                else
                    cur_R = *num - 2;
                answer.append("R");
            }
            else
            {
                if (hand == "left")
                {
                    cur_L = *num;
                    answer.append("L");
                }
                else if (hand == "right")
                {

                    if (cur_R == 2 || cur_R == 5 || cur_R == 8 || cur_R == 11)
                        cur_R = *num;
                    else
                        cur_R = *num - 2;
                    answer.append("R");
                }
            }
        }
    }
    return answer;
}

int main(void)
{
    string hand1 = "right";
    string hand2 = "left";
    string hand3 = "right";
    string hand4 = "right";

    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> numbers3;
    vector<int> numbers4;

    numbers1.push_back(1);
    numbers1.push_back(3);
    numbers1.push_back(4);
    numbers1.push_back(5);
    numbers1.push_back(8);
    numbers1.push_back(2);
    numbers1.push_back(1);
    numbers1.push_back(4);
    numbers1.push_back(5);
    numbers1.push_back(9);
    numbers1.push_back(5);

    numbers2.push_back(7);
    numbers2.push_back(0);
    numbers2.push_back(8);
    numbers2.push_back(2);
    numbers2.push_back(8);
    numbers2.push_back(3);
    numbers2.push_back(1);
    numbers2.push_back(5);
    numbers2.push_back(7);
    numbers2.push_back(6);
    numbers2.push_back(2);

    numbers3.push_back(1);
    numbers3.push_back(2);
    numbers3.push_back(3);
    numbers3.push_back(4);
    numbers3.push_back(5);
    numbers3.push_back(6);
    numbers3.push_back(7);
    numbers3.push_back(8);
    numbers3.push_back(9);
    numbers3.push_back(0);

    numbers4.push_back(2);
    numbers4.push_back(5);
    numbers4.push_back(8);
    numbers4.push_back(0);
    numbers4.push_back(1);
    numbers4.push_back(1);
    numbers4.push_back(2);
    numbers4.push_back(2);
    numbers4.push_back(5);
    numbers4.push_back(8);
    numbers4.push_back(0);

    solution(numbers4, hand4);
    return 0;
}