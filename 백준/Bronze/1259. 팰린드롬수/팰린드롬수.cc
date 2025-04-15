#include<iostream>
#include<algorithm>
using namespace std;

// 팰린드롬수 #1259
int main(){
    string s;
    while(true){
        cin >> s;
        if(s == "0") break;

        string temp = s;
        reverse(s.begin(),s.end());
        cout << (temp == s ? "yes":"no") << "\n";
    }

    return 0;
}