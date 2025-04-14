#include<iostream>
#include<vector>
using namespace std;

// 알파벳 찾기 #10809
int main(){
    vector<int> vc(26,-1);
    string s;
    cin >> s;

    int i = 0;
    for(auto c : s){
        if(vc[c - 'a'] < 0) vc[c - 'a'] = i;
        i++;
    }

    for(auto a : vc){
        cout << a << " ";
    }

    return 0;
}