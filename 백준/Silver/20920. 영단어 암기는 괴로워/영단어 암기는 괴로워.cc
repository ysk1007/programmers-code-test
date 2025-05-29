#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// 영단어 암기는 괴로워 #20920

int n,m;
string s;
map<string,int> mp;
vector<pair<string,int>> note;

bool compare(pair<string,int> a, pair<string,int> b){
    // 1. 자주 나오는 단어
    if(a.second != b.second) return a.second > b.second;

    // 2. 단어 길이가 길수록
    if(a.first.length() != b.first.length()) return a.first.length() > b.first.length();

    // 3. 알파벳 사전 순
    return a.first < b.first;
}

int main(){

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> s;
        if(s.length() < m) continue;
        mp[s]++;
    }

    for(auto m : mp){
        note.push_back({m.first,m.second});
    }

    sort(note.begin(),note.end(),compare);

    for(auto n : note){
        cout << n.first << "\n";
    }
}