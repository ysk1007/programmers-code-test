#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

// 단어 공부 #1157
int main(){
    string str;
    cin >> str;

    map<char,int> map;
    vector<char> result;
    int count = -1;

    for(auto s : str){
        char alpha = toupper(s);                    // 미리 대문자로 변환
        map[alpha]++;
    }

    for(auto m : map){                              
        if(m.second > count){                       // 갯수가 더 많으면
            result.clear();                         // 결과 초기화
            result.push_back(m.first);              // 알파벳

            count = m.second;                       // 최대 갯수 초기화
        }
        else if(m.second == count){                 // 갯수가 같으면
            result.push_back(m.first);              // 알파벳 추가
        }
    }

    cout << (result.size() > 1 ? '?' : result.front()); // 출력

    return 0;
}