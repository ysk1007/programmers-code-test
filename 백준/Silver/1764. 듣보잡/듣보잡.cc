#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

// 듣보잡 #1764

set<string> st;
vector<string> vc;

int n,m;
string s;
int main(){

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    while(n--){
        cin >> s;
        st.insert(s);
    }

    while(m--){
        cin >> s;
        if(st.find(s) != st.end()) vc.push_back(s);
    }

    sort(vc.begin(),vc.end());

    // 출력
    cout << vc.size() << "\n";
    for(auto name : vc){
        cout << name << "\n";
    }

    return 0;
}