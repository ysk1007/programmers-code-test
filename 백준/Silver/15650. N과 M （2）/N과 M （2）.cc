#include<iostream>

using namespace std;

// N과 M (2) #15650

int n,m;

int arr[10];            // 출력 내용
bool visited[10];       // 방문 내역

void dfs(int depth){    // 백트래킹
    if(depth == m){     // 깊이가 M과 같다면 출력
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 아니라면
    for(int j = 1 ; j <= n ; j++){
        if(visited[j]) continue;    // 방문 제외
        
        visited[j] = true;          // 현재 숫자 방문 체크
        arr[depth] = j;             // 현재 깊이(선택 숫자)는 j
        dfs(depth + 1);             // 다음 숫자를 선택하러 감

        for(int k = j+1 ; k <= n ; k++){    // 중복 제거하려고 처음 사용문자 제외하고 방문 해제
            visited[k] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0);
    return 0;
}