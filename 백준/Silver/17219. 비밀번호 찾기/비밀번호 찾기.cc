#include<iostream>
#include<map>
using namespace std;

// 비밀번호 찾기 #17219

map<string,string> mp;
int n,m;
string name,pw;
int main(){
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while(n--){
        cin >> name >> pw;
        mp[name] = pw;
    }

    while(m--){
        cin >> name;
        cout << mp[name] << "\n";
    }
}