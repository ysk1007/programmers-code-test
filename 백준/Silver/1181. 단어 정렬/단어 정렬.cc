#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    else{
        return a.size() < b.size();
    }
}

// 단어 정렬 #1181
int main(){
    int n;
    string s;
    vector<string> vc;
    cin >> n;
    while(n--){
        cin >> s;
        vc.push_back(s);
    }

    sort(vc.begin(),vc.end(), compare);

    vc.erase(unique(vc.begin(),vc.end()),vc.end()); // 중복 제거



    for(auto a : vc){
        cout << a << "\n";
    }

    return 0;
}