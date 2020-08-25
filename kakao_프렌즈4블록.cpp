// 
// 조건
// - 
// 접근
// - x 기준 (2x2)완전탐색 형태로 풀이 진행
// - (2x2) 기준에 부합되는 위치를 check하고 flush 하는 형태로 해결
// - (2x2)에 해당하는 블록이 하나도 없을 경우 stop
// 
// 문제풀이시 문제가 되었던 점
// - 배열 연산이 아닌 벡터 연산으로 접근할 경우 시간초과가 남. push와 replace 등의 연산 때문
#include <string>
#include <vector>

using namespace std;

#define DEF_EMPTY 0
#define DEF_FILL  1
#define DEF_BREAK 2

int board_a[30][30] = { 0 };
int check[30][30] = { 0 };

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			board_a[y][x] = board[y][x];
			check[y][x] = DEF_FILL;
		}
	}

	bool is_ing = true;

	while (is_ing)
	{
		is_ing = false;
		for (int y = 0; y < m - 1; y++)
		{
			for (int x = 0; x < n - 1; x++)
			{
				if (check[y][x] > DEF_EMPTY)
				{
					int a, b, c, d = 0;
					a = board_a[y][x];
					b = board_a[y + 1][x];
					c = board_a[y][x + 1];
					d = board_a[y + 1][x + 1];

					if (a != DEF_EMPTY)
					{
						if (a == b && b == c && c == d)
						{
							is_ing = true;
							check[y][x] = DEF_BREAK;
							check[y + 1][x] = DEF_BREAK;
							check[y][x + 1] = DEF_BREAK;
							check[y + 1][x + 1] = DEF_BREAK;
						}
					}
				}
			}
		}
		if (is_ing)
		{
			for (int y = 0; y < m; y++)
			{
				for (int x = 0; x < n; x++)
				{
					if (check[y][x] == DEF_BREAK)
					{
						answer++;

						if (y - 1 >= 0)
						{
							for (int tmp_y = y; tmp_y > 0; tmp_y--)
							{
								string tmp(1, board[tmp_y - 1][x]);
								board_a[tmp_y][x] = board_a[tmp_y - 1][x];
								board_a[tmp_y - 1][x] = DEF_EMPTY;
								check[tmp_y][x] = DEF_FILL;
								check[tmp_y - 1][x] = DEF_EMPTY;
							}
						}
					}
				}
			}
		}
	}
	return answer;
}

int main(void)
{
	vector<string> input[4];

	input[0].push_back("CCBDE");
	input[0].push_back("AAADE");
	input[0].push_back("AAABF");
	input[0].push_back("CCBBF");

	input[1].push_back("TTTANT");
	input[1].push_back("RRFACC");
	input[1].push_back("RRRFCC");
	input[1].push_back("TRRRAA");
	input[1].push_back("TTMMMF");
	input[1].push_back("TMMTTJ");


	input[2].push_back("AAAAA");
	input[2].push_back("AUUUA");
	input[2].push_back("AUUAA");
	input[2].push_back("AAAAA");

	input[3].push_back("ABCD");
	input[3].push_back("BACE");
	input[3].push_back("BCDD");
	input[3].push_back("BCDD");

	//solution(4, 5, input[0]);
	//solution(6, 6, input[1]);
	//solution(4, 5, input[2]);
	solution(4, 4, input[3]);
}