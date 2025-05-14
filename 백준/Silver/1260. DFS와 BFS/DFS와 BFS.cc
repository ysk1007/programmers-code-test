#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// DFS와 BFS #1260

int n,m,v,a,b;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int n){
    // 방문한 노드이면 return
    if(visited[n]) return;

    visited[n] = true;
    // 출력
    cout << n << " ";

    // 인접 행렬들 DFS
    for(auto g : graph[n]){
        DFS(g);
    }
}

void BFS(int n){
    queue<int> q;

    // 출발할 노드 큐에 넣기
    q.push(n);
    visited[n] = true;

    while(!q.empty()){  // 모든 노드를 접근할 때 까지

        // 대기열 첫 번째
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for(auto g : graph[temp]){  // 대기열 첫 번째의 인접 행렬들 접근
            if(visited[g]) continue;// 이미 방문했으면 스킵
            visited[g] = true;
            q.push(g);              // 방문해서 큐에 넣기
        }
    }
}

int main(){
    cin >> n >> m >> v;

    graph = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1);

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;

        // 인접 행렬 노드 연결
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 낮은 노드부터 갈거니까 정렬
    for(auto &g : graph){       // 원본 적용되게 &g
        sort(g.begin(),g.end());
    }

    DFS(v);
    cout << "\n";
    
    // 방문 초기화
    visited = vector<bool>(n+1);
    BFS(v);

    return 0;
}