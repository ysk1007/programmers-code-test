#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

// 토마토 #7569
int graph[101][101][101];
bool visited[101][101][101];

int dh[] = {1,-1};      // 높이 이동 방향
int dx[] = {1,0,-1,0};  // 가로 이동 방향
int dy[] = {0,1,0,-1};  // 세로 이동 방향

vector<tuple<int,int,int>> tomatoPos;
int m,n,h,tomato,result;

int BFS(){
    queue<pair<tuple<int,int,int>,int>> q;
    int count = 0;

    // 익어있는 토마토 위치 큐에 넣고 방문 체크
    for(auto tomato : tomatoPos){
        // 좌표 날짜 0 (깊이)
        q.push({tomato,0});
        visited[get<0>(tomato)][get<1>(tomato)][get<2>(tomato)] = true;
    }

    // 순회
    while(!q.empty()){

        // 좌표랑 날짜(깊이)
        int posH = get<0>(q.front().first);
        int posX = get<1>(q.front().first);
        int posY = get<2>(q.front().first);
        int day = q.front().second;

        q.pop();

        // 익는데 가장 오래 걸린 날짜로 갱신신
        count = max(count,day);

        // 상하좌우
        for(int i = 0 ; i < 4 ; i++){
            // 다음 이동 좌표
            int nextPosX = posX + dx[i];
            int nextPosY = posY + dy[i];

            if(nextPosX < 0 || nextPosY < 0 || nextPosX >= n || nextPosY >= m) continue;    // 범위 밖
            if(graph[posH][nextPosX][nextPosY] != 0) continue;                              // 이미 익었거나, 토마토가 없음
            if(visited[posH][nextPosX][nextPosY]) continue;                                 // 방문 했음
            visited[posH][nextPosX][nextPosY] = true;

            q.push({make_tuple(posH,nextPosX,nextPosY),day+1});
        }

        // 위아래
        for(int j = 0 ; j < 2 ; j++){
            // 다음 이동 좌표
            int nextPosH = posH + dh[j];

            if(nextPosH < 0 || nextPosH >= h) continue;     // 범위 밖
            if(graph[nextPosH][posX][posY] != 0) continue;  // 이미 익었거나, 토마토가 없음
            if(visited[nextPosH][posX][posY]) continue;     // 방문 했음
            visited[nextPosH][posX][posY] = true;

            graph[nextPosH][posX][posY] = day + 1;
            q.push({make_tuple(nextPosH,posX,posY),day+1});
        }
    }

    return count;
}

int main(){
    cin >> m >> n >> h;

    bool flag = false;

    // 토마토 상자 초기화
    for(int i = 0 ; i < h; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < m ; k++){
                cin >> tomato;
                if(tomato == 0) flag = true;                // 익어야 할 토마토가 하나라도 있음
                if(tomato == 1){
                    tomatoPos.push_back(make_tuple(i,j,k)); // 익어 있는 토마토 위치
                }
                graph[i][j][k] = tomato;                    // 토마토 넣기
            }
        }
    }

    if(flag) result = BFS();    // 익어야 할 토마토가 하나라도 있다면 순회
    else{
        cout << 0;
        return 0;
    }

    // 방문 노드 순회
    for(int i = 0 ; i < h; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < m ; k++){
                if(visited[i][j][k] == false && graph[i][j][k] == 0){   // 방문 못 했는데 거기 토마토가 있음
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    // 결과 출력력
    cout << result;

    return 0;
}