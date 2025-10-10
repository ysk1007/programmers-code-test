#include<iostream>
#include<map>
#include<queue>
using namespace std;

// 뱀과 사다리 게임 #16928

map<int,int> ladder;            // 사다리 위치
map<int,int> snake;             // 뱀 위치

int bfs(){
    bool visit[101] = {false};              // 방문 확인
    queue<pair<int,int>> que;               // {위치, 던진 횟수}

    visit[1] = true;                        // 시작 위치 1 방문 체크
    que.push({1,0});                        // 큐에 시작 위치 넣기

    while(!que.empty()){                    // 작업이 없을 때 까지 반복

        // que 맨 앞 작업 꺼내고 pop, temp에 복사
        pair<int,int> temp = que.front();
        que.pop();
        int pos = temp.first;
        int count = temp.second;

        // 주사위 칸으로 갈 수 있는 위치
        int nextPos[] = {pos+1, pos+2, pos+3, pos+4, pos+5, pos+6};

        // 다음 칸 체크
        for(int pos : nextPos){

            if(pos == 100){         // 만약 다음 칸이 도착이면 던진 횟수 +1 하고 출력
                return count + 1;
            }

            if(pos > 100 || visit[pos]) continue;       // pos가 도착지점보다 크거나, 이미 방문 했으면 continue

            visit[pos] = true;                          // 조건을 통과 했고 다음 칸은 방문 체크

            if(ladder.find(pos) != ladder.end()){       // 다음 칸에 사다리가 있으면
                visit[ladder[pos]] = true;              // 사다리 타고 이동한 위치 방문 체크
                que.push({ladder[pos],count + 1});      // 큐에 넣기
            }
            else if(snake.find(pos) != snake.end()){    // 다음 칸에 뱀이 있나
                visit[snake[pos]] = true;               // 뱀 타고 이동한 위치 방문 체크
                que.push({snake[pos],count + 1});       // 큐에 넣기
            }
            else{                                       // 평범한 칸
                que.push({pos,count+1});                // 큐에 넣기
            }
        }
    }
}

int main(){
    int n,m,x,y;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){       // 사다리 초기화
        cin >> x >> y;
        ladder[x] = y;
    }

    for(int j = 0 ; j < m ; j++){       // 뱀 초기화
        cin >> x >> y;
        snake[x] = y;
    }

    cout << bfs();                      // bfs 탐색
    return 0;
}