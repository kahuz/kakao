//
// 조건 
// - 크레인 인형뽑기 기계를 모바일 게임으로 만들려고한다
// - 게임 화면은 '1x1'크기의 칸들로 이루어진 'NxN'크기의 정사각 격자이며, 위쪽에는 크레인이 있고 오른쪽에는 바구니가 있다
// - 각 칸에는 다양한 인형이 들어있으며 인형이 없는 칸은 빈칸이다
// - 모든 인형은 1x1크기이며, 격자의 가장 아래 칸부터 차곡차곡 쌓여있다.
// - 크레인을 좌우로 움직여 멈추 ㄴ위치에서 가장 위에 있는 인형을 집어 올릴 수 있다.
// - 집어 올린 인형은 바구니에 쌓이게 되는데, 이때 바구니 가장 아래칸부터 인형이 순서대로 쌓인다
// - *만약 같은 인형이 연속으로 쌓이게 되면 두 인형은 터트려지며 바구니에서 사라진다.
// - 크레인 작동 시 인형이 집어지지 않는 경우는 없고, 인형이 없는 곳에서 크레인이 작동되면 아무일도 일어나지 않는다
// - *바구니는 모든 인형이 들어갈 수 있을만큼 충분히 크다고 가정한다
// - 게임화면 상태가 담긴 2차원배열 board와 크레인 작동 위치가 담긴 배열 moves가 변수로 주어질때 크레인을 모두 작동시킨 후 "터져 사라진 인형의 개수"를 넘겨라
//
// 입력
// - 게임 화면상태를 가진 board ( 5x5 <= board <= 30x30 )
//	-> board의 값 : 0은 빈칸, 1~100은 각각 다른 모양의 인형
// - 크레인의 동작배열 moves ( 1<= moves <= 1000 )
//	-> moves의 값 : board의 column index를 표현하며, index 값은 1 ~ board의 column 값 까지이다.
//	-> 단, 인덱스를 1부터 표현하기에 배열 기준으로 작업할 경우 index -1 로 인덱스 매칭할 것
//
// 접근
// - 단순 시뮬레이션으로 접근.
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> basket;
//
//int solution(vector<vector<int>> board, vector<int> moves)
//{
//	int answer = 0;
//	int crain_n = 0;
//	for (int m_idx = 0; m_idx < moves.size(); m_idx++)
//	{
//		crain_n = moves[m_idx] - 1;
//
//		for (int b_idx = 0; b_idx < board.size(); b_idx++)
//		{
//			if (board[b_idx][crain_n] != 0)
//			{
//				if (basket.size() > 0 && basket.back() == board[b_idx][crain_n])
//				{
//					basket.pop_back();
//					answer+= 2;
//				}
//				else
//				{
//					basket.push_back(board[b_idx][crain_n]);
//				}
//
//				board[b_idx][crain_n] = 0;
//				break;
//			}
//		}
//	}
//
//	return answer;
//}
//int main(void)
//{
//	vector<vector<int>> t_board;
//	vector<int> t_moves;
//
//	vector<int> b_1;
//	vector<int> b_2;
//	vector<int> b_3;
//	vector<int> b_4;
//	vector<int> b_5;
//
//	b_1.push_back(0);
//	b_1.push_back(0);
//	b_1.push_back(0);
//	b_1.push_back(0);
//	b_1.push_back(0);
//
//	b_2.push_back(0);
//	b_2.push_back(0);
//	b_2.push_back(1);
//	b_2.push_back(0);
//	b_2.push_back(3);
//
//
//	b_3.push_back(0);
//	b_3.push_back(2);
//	b_3.push_back(5);
//	b_3.push_back(0);
//	b_3.push_back(1);
//
//	b_4.push_back(4);
//	b_4.push_back(2);
//	b_4.push_back(4);
//	b_4.push_back(4);
//	b_4.push_back(2);
//
//	b_5.push_back(3);
//	b_5.push_back(5);
//	b_5.push_back(1);
//	b_5.push_back(3);
//	b_5.push_back(1);
//
//	t_board.push_back(b_1);
//	t_board.push_back(b_2);
//	t_board.push_back(b_3);
//	t_board.push_back(b_4);
//	t_board.push_back(b_5);
//
//	t_moves.push_back(1);
//	t_moves.push_back(5);
//	t_moves.push_back(3);
//	t_moves.push_back(5);
//	t_moves.push_back(1);
//	t_moves.push_back(2);
//	t_moves.push_back(1);
//	t_moves.push_back(4);
//
//	cout << solution(t_board, t_moves) << endl;
//
//	return 0;
//}