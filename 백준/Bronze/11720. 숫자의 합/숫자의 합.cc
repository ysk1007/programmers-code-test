#include<iostream>

using namespace std;

// 숫자의 합 #11720
int main(){
    int n,result = 0;
    string s;

    cin >> n >> s;

    for(auto c : s){
        result += c - '0';
    }
    cout << result;
    return 0;
}