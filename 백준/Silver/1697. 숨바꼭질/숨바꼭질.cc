#include<iostream>
#include<queue>
using namespace std;

// 숨바꼭질 #1697
int main(){
    int n,k;
    queue<pair<int,int>> que;
    int visit[100001] = {false};
    cin >> n >> k;

    que.push({n,0});                                            // 큐에 시작 위치 넣기 {위치, 현재 소요한 시간}

    while(!que.empty()){
        pair<int,int> temp = que.front();                       // 큐에서 꺼내기
        que.pop();

        int pos = temp.first;                                   // 위치 저장
        int time = temp.second;                                 // 시간 저장

        visit[pos] = true;                                      // 방문 체크

        if(pos == k) {                                          // 위치 찾으면 반환
            cout << time;
            return 0;   
        }

        int nextPos[] = {pos * 2, pos + 1, pos - 1};            // 탐색할 다음 위치

        for(auto np : nextPos){
            if(np < 0 || np > 100000 || visit[np]) continue;    // 다음 위치가 음수, 범위초과, 이미 방문 했으면 continue

            que.push({np, time + 1});                           // que에 {다음위치, +1초} 넣기
        }
        
    }

    return 0;
}