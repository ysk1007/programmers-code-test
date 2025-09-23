#include<iostream>
#include<vector>
using namespace std;

// 유기농 배추 #1012

int t,m,n,k,x,y;
vector<vector<int>> vc;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n) return 0;    // 농장 밖이면 return
    if(vc[x][y] == 0) return 0;                         // 배추 없으면 return
    
    vc[x][y] = 0;                                       // 다시 방문 안 하게 0으로 초기화 (동일한 크기의 visit 배열 만들어서 사용해도 됨)
    for(int i = 0 ; i < 4 ; i++){
        dfs(x+dx[i],y+dy[i]);                           // 주위 4방향 노드에 dfs 호출 (주변 1을 검출하고 0으로 초기화)
    }                                                   // 결과적으로 인접한 배추를 다 0으로 만들었음

    return 1;                                           // 붙어 있는 배추 모임 return 1
}

int main(){
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        cin >> m >> n >> k;
        int result = 0;                                 // 반환값

        vc = vector<vector<int>>(m,vector<int>(n,0));   // vc[m][n] 사이즈 vector를 0으로 초기화

        for(int i = 0 ; i < k ; i++){
            cin >> x >> y;                              // 배추 위치 받아서 1로 초기화
            vc[x][y] = 1;
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                result += dfs(i,j);                     // 전체 돌면서 dfs 호출
            }
        }

        cout << result << "\n";                         // 출력
    }
}