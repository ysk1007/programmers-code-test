#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 단지번호붙이기 #2667

vector<vector<int>> dfs;
vector<vector<bool>> visited;
vector<int> map;
int n;
string line;

vector<int> dx = {1,0,-1,0};    // 좌우 이동 방향
vector<int> dy = {0,1,0,-1};    // 상하 이동 방향

int DFS(int x, int y){
    if(x == 0 || x > n) return 0;
    if(y == 0 || y > n) return 0;
    if(visited[x][y]) return 0;

    int count = 0;
    visited[x][y] = true;

    if(dfs[x][y] == 1){
        count++;
        // 상하좌우 검사
        for(int i = 0; i < 4 ; i++){
            count += DFS(x + dx[i],y + dy[i]);
        }
    }

    return count;
}

int main(){
    cin >> n;
    
    dfs = vector<vector<int>>(n+1,vector<int>(n+1));
    visited = vector<vector<bool>>(n+1,vector<bool>(n+1));

    // 지도 읽기
    for(int i = 1 ; i <= n; i++){
        cin >> line;
        for(int j = 1 ; j <= n ; j++){
            dfs[i][j] = line[j-1] - '0';
        }
    }

    // 단지를 찾아서 평수가 0이 아니면 저장
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= n ; j++){
           int danji = DFS(i,j);
           dfs[i][j] = danji;
           if(danji != 0){
                map.push_back(danji);
           }
        }
    }

    // 최종 출력
    sort(map.begin(),map.end());
    cout << map.size() << "\n";
    for(auto m : map){
        cout << m << "\n";
    }

    return 0;
}