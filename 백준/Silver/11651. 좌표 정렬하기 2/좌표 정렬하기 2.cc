#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

// 좌표 정렬하기 2 #11651
int main(){
    int t,x,y;
    vector<pair<int,int>> vc;
    cin >> t;
    while(t--){
        cin >> x >> y;
        pair<int,int> p = {x,y};
        vc.push_back(p);
    }

    sort(vc.begin(),vc.end(),compare);

    for(pair<int,int> p : vc){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}