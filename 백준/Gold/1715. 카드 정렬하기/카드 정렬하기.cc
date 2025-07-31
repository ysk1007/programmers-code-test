#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 카드 정렬하기 #1715

// greedy : 매 순간 최선의 선택 해야함
// 매 순간 가장 적은 뭉치(가장 높은 우선순위)끼리 비교 해야함
// 우선순위 큐 사용

int main(){
    int t, n;
    long long result = 0;
    cin >> t;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i = 0 ; i < t ; i++){
        cin >> n;
        pq.push(n);
    }

    while(true){
        long long i = pq.top();
        pq.pop();

        if(pq.empty()){
            cout << result;
            return 0;
        }

        long long j = pq.top();
        pq.pop();

        result += i + j;
        long long k = i + j;
        pq.push(k);
    }
}