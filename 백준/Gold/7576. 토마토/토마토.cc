#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int box[1001][1001];
bool visited[1001][1001];
vector<pair<int,int>> tPos;

int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};

int n,m,t,result = 0;
bool pass = false;

int BFS(){
    queue<pair<pair<int,int>,int>> que;

    for(auto t : tPos){
        visited[t.first][t.second] = true;
        que.push({t,0});
    }

    int count = 0;
    while(!que.empty()){
        pair<pair<int,int>,int> temp = que.front();
        int posX = temp.first.first;
        int posY = temp.first.second;
        int day = temp.second;

        que.pop();

        count = max(count, day);
        for(int i = 0 ; i < 4 ; i++){
            int nextX = posX + dx[i];
            int nextY = posY + dy[i];
            if(nextX < 0 || nextY < 0 || nextX >= m || nextY >= n) continue;    // 범위 밖
            if(visited[nextX][nextY]) continue;                                 // 이미 방문
            if(box[nextX][nextY] == -1) continue;                               // 토마토 없는 칸

            visited[nextX][nextY] = true;
            box[nextX][nextY] = day + 1;
            que.push({{nextX,nextY},day + 1});
        }
    }

    return count;
}

// 토마토 #7576
int main(){
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> t;
            if(t == 1) tPos.push_back({i,j});
            if(t == 0) pass = true;
            
            box[i][j] = t;
        }
    }
    
    if(!pass){      // 익혀야 할 토마토가 없음
        cout << 0;
        return 0;
    }

    result = BFS();

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visited[i][j] == false && box[i][j] == 0){   // 방문 못 한 곳에 익혀야 할 토마토가 있음
                cout << -1;
                return 0;
            }
        }
    }

    cout << result;
}