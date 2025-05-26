#include <string>
#include <vector>
using namespace std;

// 6:46 # 46점 제한조건 4번
// 14:10
string solution(string s) {
    string answer = "";
    bool check = false;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            answer += " ";
            check = false;
        }
        else{
            answer += check ? tolower(s[i]) : toupper(s[i]);
            check = true;
        }
    }
    
    return answer;
}