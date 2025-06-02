#include<iostream>
#include<algorithm>
using namespace std;

// 소트인사이드 #1427
int main(){
    string s;

    cin >> s;

    sort(s.begin(),s.end(),greater<>());

    cout << s;
}