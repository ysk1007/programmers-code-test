#include<iostream>
#include<algorithm>

using namespace std;

// 팰린드롬인지 확인하기 #10988
int main(){
    string str;
    cin >> str;

    string temp = str;                      // 복사
    reverse(temp.begin(), temp.end());      // 뒤집기

    cout << (str == temp ? 1 : 0);

    return 0;
}