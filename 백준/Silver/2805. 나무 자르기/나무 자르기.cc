#include<iostream>
#include<vector>
using namespace std;

// 나무 자르기 #2805
long long t,m,h;
long long st,x,en;
vector<long long> vc;
int main(){
    cin >> t >> m;

    long long maxH = 0;
    for(int i = 0 ; i < t ; i++){
        cin >> h;
        maxH = max(maxH, h);
        vc.push_back(h);
    }

    st = 0;
    en = maxH;
    long long answer = -1;

    while(st <= en){
        x = (st + en) / 2;  // 자를 지점
        long long count = 0;
        for(auto v : vc){
            if(x >= v) continue;
            count += v - x;
        }
        if(count >= m){
            answer = x; // 조건 만족하므로 정답 후보 저장
            st = x + 1; // 더 높은 x 시도
        }
        else{
            en = x - 1;
        }
    }

    cout << answer;

    return 0;
}