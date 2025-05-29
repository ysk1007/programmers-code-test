#include<iostream>
#include<map>
using namespace std;

// 붙임성 좋은 총총이 #26069

int t;
string a,b;
string target = "ChongChong";
map<string,bool> mp;

int main(){
    cin >> t;

    mp[target] = true;

    while(t--){
        cin >> a >> b;
        if(!mp[a] && !mp[b]) continue;

        mp[a] = true;
        mp[b] = true;
    }

    int result = 0;
    for(auto m : mp){
        if(m.second) result++;
    }

    cout << result;

    return 0;
}