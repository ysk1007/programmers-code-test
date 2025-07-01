#include<iostream>

using namespace std;

// N과 M (3) #15651

int n,m;
int arr[10];
// bool visited[10];

void dfs(int depth){
    if(depth == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int j = 1 ; j <= n ; j++){
        // 모든 조건을 출력해야 해서 방문 조건 제외함
        arr[depth] = j;
        dfs(depth+1);
    }
}

int main(){
    cin >> n >> m;
    dfs(0);
    return 0;
}