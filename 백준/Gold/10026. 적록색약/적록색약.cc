#include<iostream>
#include<vector>

using namespace std;

// 적록색약 #10026
vector<vector<char>> dfs,dfsTemp;
vector<vector<bool>> visited,visitedTemp;
int t;
string line;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int DFS(int x, int y, char c){
    if(x < 0 || y < 0 || x >= t || y >= t) return 0;
    if(dfs[x][y] != c) return 0;
    if(visited[x][y]) return 0;

    visited[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        DFS(x + dx[i], y + dy[i], c);
    }

    return 1;
}


int main(){
    cin >> t;
    dfs = vector<vector<char>>(t, vector<char>(t));
    dfsTemp = vector<vector<char>>(t, vector<char>(t));
    visited = vector<vector<bool>>(t, vector<bool>(t));

    for(int i = 0 ; i < t ; i++){
        cin >> line;
        for(int j = 0 ; j < t ; j++){
            char c = line[j];
            dfs[i][j] = c;

            if(c != 'B') c = 'X';
            dfsTemp[i][j] = c;
        }
    }

    visitedTemp = visited;

    int count = 0;
    for(int i = 0 ; i < t ; i++){
        for(int j = 0 ; j < t ; j++){
            count += DFS(i,j,dfs[i][j]);
        }
    }

    cout << count;

    dfs = dfsTemp;
    visited = visitedTemp;

    count = 0;
    for(int i = 0 ; i < t ; i++){
        for(int j = 0 ; j < t ; j++){
            count += DFS(i,j,dfs[i][j]);
        }
    }

    cout << " " << count;
}
