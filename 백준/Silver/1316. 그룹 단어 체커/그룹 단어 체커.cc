#include<iostream>
#include<map>
using namespace std;

// 그룹 단어 체커 #1316
int main(){
    int t, result = 0;
    string word;
    cin >> t;

    for(int i = 0 ; i < t ; i++){
        cin >> word;

        map<char,bool> mp;                                  // 사용 체크
        bool isGroup = true;                                // 그룹 단어 확인
        char temp = ' ';                                    // 이전 글자 체크용

        for(auto c : word){
            if(temp != ' ' && temp != c && mp[c] == true){  // 이전 글자와 다른데, 이미 사용한 적이 있다.
                isGroup = false;                            // 그룹 단어 아니니까 바로 break
                break;
            }

            temp = c;
            mp[c] = true;
        }

        result += isGroup ? 1 : 0;                          // 그룹 단어 ? +1 : +0

        temp = ' ';                                         // 이전 글자 초기화
    }
    
    cout << result;

    return 0;
}