#include<iostream>
#include<queue>
using namespace std;


int n,m;
string s;
int graph[101][101];
bool visited[101][101];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void BFS(){
    queue<pair<pair<int,int>,int>> que;

    que.push({{0,0},1});
    visited[0][0] = true;

    while(!que.empty()){
        int posX = que.front().first.first;
        int posY = que.front().first.second;
        int depth = que.front().second;
        
        que.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nextX = posX + dx[i];
            int nextY = posY + dy[i];

            if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
            if(graph[nextX][nextY] == 0) continue;
            if(visited[nextX][nextY]) continue;

            visited[nextX][nextY] = true;
            graph[nextX][nextY] =  depth + 1;
            que.push({{nextX,nextY},depth+1});
        }
    }
}

// 미로 탐색 #2178
int main(){
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> s;
        for(int j = 0 ; j < m ; j++){
            graph[i][j] = s[j] - '0';
        }
    }

    BFS();

    cout << graph[n-1][m-1];
}