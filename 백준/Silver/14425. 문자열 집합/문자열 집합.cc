#include<iostream>
#include<map>
using namespace std;

// 문자열 집합 #14425

map<string,bool> st;
int n,m,result = 0;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    while(n--){
        cin >> s;
        st[s] = true;
    }

    while(m--){
        cin >> s;
        if(st[s]) result++;
    }

    cout << result;
}