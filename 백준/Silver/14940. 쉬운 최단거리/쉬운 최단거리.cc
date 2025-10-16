#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

// 쉬운 최단거리 #14940

int n, m, tx, ty, type;
int arr[1001][1001];
bool visit[1001][1001];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void bfs(int x, int y){
    queue<tuple<int,int,int>> que;              // {x좌표, y좌표, 깊이}

    que.push({x,y,0});                          // 시작 위치와 깊이 넣기
    
    while(!que.empty()){                        // 작업이 없을 때 까지

        // que 맨 앞 작업 꺼내서
        tuple<int,int,int> temp = que.front();
        que.pop();

        // 데이터 가져옴
        int posX = get<0>(temp);
        int posY = get<1>(temp);
        int depth = get<2>(temp);

        arr[posX][posY] = depth;        // 현재 위치에 깊이 저장

        // 상하좌우 탐색
        for(int i = 0 ; i < 4 ; i++){

            // 다음 위치
            int nextX = posX + dx[i];
            int nextY = posY + dy[i];

            // 필터 조건        
            if(nextX > n || nextX < 0 || nextY > m || nextY < 0) continue;  // 1. 범위 밖
            if(visit[nextX][nextY]) continue;                               // 2. 이미 방문
            if(arr[nextX][nextY] == 0) continue;                            // 3. 벽 (방문 불가)


            que.push({nextX,nextY,depth + 1});      // 큐에 {다음 방문 위치, 깊이} 넣기
            visit[nextX][nextY] = true;             // 큐에 넣자마자 방문 체크
        }
    }
}

int main(){
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // 지도 세팅
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> type;
            if(type == 2){      // 시작 위치 저장
                tx = i;
                ty = j;
            }
            arr[i][j] = type;
        }
    }

    // 시작 위치에서 bfs 시작
    bfs(tx,ty);

    // 출력
    int r;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            r = arr[i][j];

            if(r == 0 && !visit[i][j]) cout << 0 << " ";        // 0인데 방문 못 했으면 벽
            else if(r != 0 && !visit[i][j]) cout << -1 << " ";  // 벽이 아닌데 방문 못 했으면 -1
            else cout << r << " ";                              // 깊이 출력
        }
        cout << "\n";
    }

    return 0;
}