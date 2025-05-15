#include<iostream>
#include<vector>
using namespace std;

// 헌내기는 친구가 필요해 #21736

vector<vector<char>> dfs;
vector<vector<bool>> visited;
pair<int,int> iPos;
int n,m, result = 0;
string line;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void DFS(int x, int y){
    if(x == 0 || x > n || y == 0 || y > m) return;
    if(visited[x][y] == true) return;

    visited[x][y] = true;
    if(dfs[x][y] == 'X') return;

    if(dfs[x][y] == 'P') result++;
    
    for(int i = 0 ; i < 4 ; i++){
        DFS(x + dx[i], y + dy[i]);
    }
}

int main(){
    cin >> n >> m;

    dfs = vector<vector<char>>(n+1,vector<char>(m+1));
    visited = vector<vector<bool>>(n+1,vector<bool>(m+1));

    for(int i = 1 ; i <= n ; i++){
        cin >> line;
        for(int j = 1 ; j <= m ; j++){
            char c = line[j-1];
            if(c == 'I'){
                iPos.first = i;
                iPos.second = j;
            }
            dfs[i][j] = c;
        }
    }

    DFS(iPos.first,iPos.second);

    if(result > 0) cout << result;
    else cout << "TT";

    return 0;
}