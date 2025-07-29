#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool option(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

// 회의실 배정 #1931
int main(){
    int t,n,m, count = 0;
    cin >> t;

    vector<pair<int,int>> list(t);
    pair<int,int> temp;

    for(int i = 0 ; i < t ; i++)
    {
        cin >> n >> m;
        list[i] = {n,m};
    }

    // 끝나는 시간이 빠른 회의를 우선으로 정렬해야 많이 배정할 수 있음. (최선 찾는 것 중요)
    sort(list.begin(),list.end(), option);

    temp = list[0];
    count++;
    
    for(int i = 1 ; i < t ; i++){
        if(temp.second <= list[i].first){
            temp = list[i];
            count++;
        }
    }

    cout << count;
}