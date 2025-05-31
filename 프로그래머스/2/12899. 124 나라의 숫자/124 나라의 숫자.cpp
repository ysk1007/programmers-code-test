#include <string>
#include <vector>
#include <algorithm>
// 37:40
// 검색해서 힌트를 얻음
using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> num = {"1","2","4"};
    while(n > 0){
        //n은 -1해주어야 인덱스 뽑기가 좋다.
        n -= 1;
        
        answer += num[n%3];
        n /= 3;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}