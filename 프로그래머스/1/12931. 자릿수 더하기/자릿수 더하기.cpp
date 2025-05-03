#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string s = to_string(n);
    
    for(auto v : s){
        answer += v - '0';
    }

    return answer;
}