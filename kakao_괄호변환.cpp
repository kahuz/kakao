// 8:25 시작 8:55 스탑 (30m), 시작 9:05 끝 : 9:49 , 총 시간 : 1시간15분
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solve(string w)
{
    //1. 입력이 빈 문자열이라면 빈 문자열을 반환한다
    if (w == "")
    {
        return w;
    }

    //2. 문자열 w를 두 "균형잡힌 괄호 문자열" u,v로 분리한다
    //단, u는 균형잡힌 문자열로 더이상 분리할 수 없어야하며!
    // - v는 빈 문자열이 될 수 있습니다
    else
    {
        string u = "", v = "";
        int close_n = 0, open_n = 0;
        bool is_currect = false;

        for (int i = 0; i < w.size(); i++)
        {
            if (w[i] == ')')
            {
                close_n++;
            }
            else if (w[i] == '(')
            {
                open_n++;
            }

            if (close_n == open_n)
            {
                u = w.substr(0,i+1);
                v = w.substr(i + 1, w.size());
                break;
            }
        }

        //3. 문자열 u가 올바른 괄호 문자열 이라면, 문자열 v에 대해 1단계부터 다시 수행
        // - 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
        // - 즉, u는 올바른 괄호 문자열이 이어지도록 만들어주자! (?)
        if(u[0] == '(')
        {
            int open_n = 0, close_n = 0, oc_sum = 0;

            for (int i = 0; i < u.size(); i++)
            {
                if (u[i] == '(')
                    open_n++;
                else if (u[i] == ')')
                    close_n++;

                if (open_n == close_n)
                {
                    if (u.size() == open_n + close_n)
                        is_currect = true;
                    break;
                }
            }
            
            if(is_currect)
                v = solve(v);
            w = u + v;
        }
        //4. 문자열 u가 올바른 괄호 문자열이 아니라면 아래와 같이 수행한다
        // - 빈 문자열에 첫번째 문자로 '('를 붙인다
        // - 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙인다.
        // - ')'를 다시 붙인다
        // - u의 첫번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙인다.
        // - 생성된 문자열을 반환한다.
        if(is_currect == false)
        {
            string tmp_u = "";
            tmp_u += "(";
            tmp_u += solve(v);
            tmp_u += ")";

            for (int j = 1; j < u.size() - 1; j++)
            {
                if (u[j] == ')')
                    tmp_u += "(";
                else if (u[j] == '(')
                    tmp_u += ")";
            }

            w = tmp_u;
        }
    }

    return w;
}
string solution(string p) {
    string answer = "";

    //1. 입력이 빈 문자열이라면 빈 문자열을 반환한다
    if (p == "")
        return "";
    else
        answer = solve(p);
    return answer;
}

int main(void)
{
    vector<string> p;
    vector<string>::iterator p_it;

   // p.push_back("(()())()");
    p.push_back(")(");
    p.push_back("()))((()");

    p_it = p.begin();

    while (p_it != p.end())
    {
        
        cout << *p_it << "solve = " <<solution(*p_it) << endl;
        p_it++;
    }
    return 0;
}