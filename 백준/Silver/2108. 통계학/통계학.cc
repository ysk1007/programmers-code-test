#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

// 통계학 #2108

int t,n;
long long sum = 0;
vector<pair<int,int>> mode;
vector<int> vc;
map<int,int> mp;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second > b.second) return false;
    else if(a.second == b.second) return a.first < b.first;
    else return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;   // t는 무조건 홀수

    for(int i = 0 ; i < t ; i++){
        cin >> n;
        sum += n;
        mp[n]++;
        vc.push_back(n);
    }

    for(auto m : mp){
        pair<int,int> p = {m.first, m.second};
        mode.push_back(p);
    }

    int avg = round((double)sum/t); // 1. 산술평균
    if(avg == 0) avg = 0;

    sort(vc.begin(),vc.end());

    int range = mode.back().first - mode.front().first; // 4. 범위

    // 최빈값으로 정렬
    sort(mode.begin(),mode.end(),compare);
    int mod;

    if(mode.size() == 1) mod = mode.front().first;  // 값이 하나
    else if(mode.back().second == mode[mode.size() - 2].second){ // 최빈값 여러개
        int i = mode.back().second;
        int count = 0;
        for(auto m : mode){
            if(m.second != i) continue;

            if(count > 0){
                mod = m.first;
                break;
            }
            count++;
        }
    }
    else mod = mode.back().first;  // 최빈값 한 개



    // 출력
    cout << avg << "\n";
    cout << vc[t/2] << "\n";
    cout << mod << "\n";
    cout << range;
}