#include<iostream>
#include<vector>
using namespace std;

// 유기농 배추 #1012

vector<vector<int>> graph;
vector<vector<int>> visited;
int t,m,n,k,x,y;

int dfs(int dx, int dy){
    if(dx >= graph.size() || dx < 0) return 0;
    if(dy >= graph[0].size() || dy < 0) return 0;
    if(visited[dx][dy] == 1) return 0;

    visited[dx][dy] = 1;

    if(graph[dx][dy] == 1){
        dfs(dx+1,dy);
        dfs(dx-1,dy);
        dfs(dx,dy+1);
        dfs(dx,dy-1);

        return 1;
    }
    return 0;
}

int main(){

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        cin >> m >> n >> k;
        visited = vector<vector<int>>(m,vector<int>(n));
        graph = vector<vector<int>>(m,vector<int>(n));

        while(k--){
            cin >> x >> y;
            graph[x][y] = 1;
        }

        int count = 0;
        for(int i = 0 ; i < graph.size() ; i++){
            for(int j = 0 ; j < graph[0].size() ; j++){
                count += dfs(i,j);
            }
        }

        cout << count << "\n";
    }
}