#include<iostream>
#include<map>
using namespace std;

// 인사성 밝은 곰곰이 #25192
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, count = 0;
    string str;
    map<string,bool> mp;
    bool flag = false;
    cin >> t;

    for(int i = 0 ; i < t ; i++){
        cin >> str;
        if(str == "ENTER" && !flag){
            flag = true;
        }
        else if(str == "ENTER" && flag){
            mp = map<string,bool>();
        }
        else{
            if(mp[str]) continue;
            count++;
            mp[str] = true;
        }
    }

    cout << count;
}