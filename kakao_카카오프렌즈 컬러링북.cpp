

#include <vector>
#include <queue>

using namespace std;

int draw[101][101];
int check[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int M = 0, N = 0;
queue<pair<int, int>> bfs_q;

int bfs(int start_x, int start_y)
{
    int area_n = 1;
    int area_color = draw[start_y][start_x];
    bfs_q.push(make_pair(start_x, start_y));
    check[start_y][start_x] = 1;

    while (!bfs_q.empty())
    {
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;

        bfs_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xn = x + dx[i];
            int yn = y + dy[i];

            if (xn < 0 || xn >= N || yn < 0 || yn >= M)   continue;

            if (check[yn][xn] == 0 && draw[yn][xn] == area_color)
            {
                check[yn][xn] = 1;
                bfs_q.push(make_pair(xn, yn));
                area_n++;
            }
        }

    }
    return area_n;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    memset(check, false, sizeof(check));
    memset(draw, false, sizeof(draw));
    M = m; 
    N = n;

    for (int y = 0; y < m; y++)
    {
        vector<int> tmp = picture[y];
        for (int x = 0; x < n; x++)
        {
            draw[y][x] = tmp[x];
        }
    }

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (check[y][x] == 0 && draw[y][x] != 0)
            {
                int cur_area_n = bfs(x,y);

                if (max_size_of_one_area < cur_area_n)
                    max_size_of_one_area = cur_area_n;

                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}

int main(void)
{
    //[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]
    vector<vector<int>> input;

   //vector<int> a1;
   //a1.push_back(1);
   //a1.push_back(1);
   //a1.push_back(1);
   //a1.push_back(0);
   //vector<int> a2;
   //a2.push_back(1);
   //a2.push_back(2);
   //a2.push_back(2);
   //a2.push_back(0);
   //
   //vector<int> a3;
   //a3.push_back(1);
   //a3.push_back(0);
   //a3.push_back(0);
   //a3.push_back(1);
   //
   //vector<int> a4;
   //a4.push_back(0);
   //a4.push_back(0);
   //a4.push_back(0);
   //a4.push_back(1);
   //vector<int> a5;
   //a5.push_back(0);
   //a5.push_back(0);
   //a5.push_back(0);
   //a5.push_back(3);
   //vector<int> a6;
   //a6.push_back(0);
   //a6.push_back(0);
   //a6.push_back(0);
   //a6.push_back(3);

   // vector<int> a1;
   // a1.push_back(1);
   // a1.push_back(0);
   // a1.push_back(1);
   // a1.push_back(0);
   // vector<int> a2;
   // a2.push_back(0);
   // a2.push_back(1);
   // a2.push_back(0);
   // a2.push_back(1);
   //
   // vector<int> a3;
   // a3.push_back(1);
   // a3.push_back(0);
   // a3.push_back(1);
   // a3.push_back(0);
   //
   // vector<int> a4;
   // a4.push_back(0);
   // a4.push_back(1);
   // a4.push_back(0);
   // a4.push_back(1);
   // vector<int> a5;
   // a5.push_back(1);
   // a5.push_back(0);
   // a5.push_back(1);
   // a5.push_back(0);
   // vector<int> a6;
   // a6.push_back(0);
   // a6.push_back(1);
   // a6.push_back(0);
   // a6.push_back(1);

    vector<int> a1;
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);

    vector<int> a2;
    a2.push_back(1);
    a2.push_back(1);
    a2.push_back(1);
    a2.push_back(1);
    a2.push_back(1);

    vector<int> a3;
    a3.push_back(1);
    a3.push_back(1);
    a3.push_back(1);
    a3.push_back(1);
    a3.push_back(1);

    vector<int> a4;
    a4.push_back(1);
    a4.push_back(1);
    a4.push_back(1);
    a4.push_back(1);
    a4.push_back(1);

    vector<int> a5;
    a5.push_back(1);
    a5.push_back(1);
    a5.push_back(1);
    a5.push_back(1);
    a5.push_back(1);

    input.push_back(a1);
    input.push_back(a2);
    input.push_back(a3);
    input.push_back(a4);
    input.push_back(a5);

    solution(5,5,input);
    return 0;
}