#include<iostream>
using namespace std;

// N-Queen #9663
int n, result = 0;

int arr[16][16];
bool visitedX[16];
int visited[16][16];

// 디버깅
void debug(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "=======\n";
}

void dfs(int x, int y){   // 현재 놓은 말 개수, x 좌표, y 좌표
    if(y == n){                 // 말을 목표 n개 놨으면 성공
        result++;
        // debug();
        return;
    }

    for(int i = 0 ; i < n ; i++){   // 모든 줄 체크
        if(visitedX[i]) continue;   // 현재 줄에 놓을수 있는지 확인
        if(visited[i][y] != 0) continue; // 현재 칸에 놓을수 있는지 확인

        arr[i][y] = 1;              // 퀸 배치
        
        // 현재 줄, 대각선 막기
        visitedX[i] = true;
        for(int j = 1 ; y + j <= n ; j++){
            if(i+j <= n) visited[i+j][y+j]++;
            if(i-j >= 0) visited[i-j][y+j]++;
        }

        dfs(i, y+1);                // 옆칸으로 가서 다시 놓을 수 있는 줄 찾기

        arr[i][y] = 0;              // 퀸 회수

        // 방문 회수
        visitedX[i] = false;
        for(int k = 1 ; y + k <= n ; k++){
            if(i+k <= n) visited[i+k][y+k]--;
            if(i-k >= 0) visited[i-k][y+k]--;
        }
        
    }
}


int main(){
    cin >> n;

    // 맨 왼쪽에 하나씩 놓고 시작
    dfs(0,0);

    cout << result;
    return 0;
}