#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 쉬운 최단거리 #14940

int n,m,q;
int x,y;
vector<vector<int>> bfs;
vector<vector<bool>> visited;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void BFS(int x, int y){

    // 대기열
    queue<pair<pair<int,int>,int>> que;

    // 시작작 좌표 방문
    visited[x][y] = true;
    bfs[x][y] = 0;

    // 시작 좌표 대기열에 추가
    que.push({{x,y},0});

    while(!que.empty()){
        // <좌표,깊이>
        pair<pair<int,int>,int> temp = que.front();
        que.pop();

        // 현재 좌표랑 깊이
        int curX = temp.first.first;
        int curY = temp.first.second;
        int depth = temp.second;

        // 상하좌우 방문
        for(int i = 0 ; i < 4 ; i++){
            int posX = curX + dx[i];    // 이동할 X좌표
            int posY = curY + dy[i];    // 이동할 Y좌표

            if(posX < 0 || posX >= n || posY < 0 || posY >= m) continue;    // 맵 초과
            if(visited[posX][posY]) continue;                               // 방문한 노드일 때
            if(bfs[posX][posY] == -1) continue;                             // 벽일 때

            // 현재 좌표 방문
            visited[posX][posY] = true;

            bfs[posX][posY] = depth + 1;
            que.push({{posX,posY}, depth + 1});
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    bfs = vector<vector<int>>(n,vector<int>(m));
    visited = vector<vector<bool>>(n,vector<bool>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> q;
            if(q==2){
                x = i;
                y = j;
            }
            if(q==0){
                bfs[i][j] = -1;
            }
        }
    }

    BFS(x,y);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(bfs[i][j] != -1 && visited[i][j] == false) cout << -1 << " ";    // 벽이 아닌데 방문하지 못 한 경우
            else if(bfs[i][j] == -1) cout << 0 <<" ";                           // 벽은 0으로 출력
            else cout << bfs[i][j] <<" ";                                       // 그 외에는 깊이 출력
        }
        cout << "\n";
    }
}