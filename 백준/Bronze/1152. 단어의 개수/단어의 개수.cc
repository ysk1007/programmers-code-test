#include<iostream>
#include<map>
using namespace std;

// 단어의 개수 #1152
int main(){
    map<string,int> m;
    string s;
    int count = 0;
    while(cin >> s){
        m[s]++;
    }

    for(auto a : m){
        count += a.second;
    }

    cout << count;
    return 0;
}