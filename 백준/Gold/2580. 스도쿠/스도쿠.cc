#include<iostream>
#include<vector>
using namespace std;

// 스도쿠 #2580

int n;
bool clear = false;
int sudoku[9][9];
vector<pair<int,int>> blank;

bool isAble(pair<int,int> p){
    // 현재 칸 숫자
    int num = sudoku[p.first][p.second];

    // 같은 행 검사
    for(int i = 0 ; i < 9 ; i++){
        if(i == p.first) continue;      // 동일 칸 건너뛰기
        if(sudoku[i][p.second] == num) return false;    // 중복 발견
    }

    // 같은 열 검사
    for(int j = 0 ; j < 9 ; j++){
        if(j == p.second) continue;     // 동일 칸 건너뛰기
        if(sudoku[p.first][j] == num) return false; // 중복 발견
    }

    // 같은 섹션 검사
    int px = (p.first / 3) * 3;
    int py = (p.second / 3) * 3;

    for(int x = 0 ; x < 3 ; x++){
        for(int y = 0 ; y < 3 ; y++){
            if(px + x == p.first && py + y == p.second) continue;   // 동일 칸 건너뛰기

            if(sudoku[px + x][py + y] == num) return false;         // 중복 발견
        }
    }

    // 사용 가능
    return true;
}

// 재귀 함수
void dfs(int depth){
    // 모든 칸 채웠으면 clear 체크하고 return
    if(depth == blank.size()){
        clear = true;
        return;
    }

    // 빈 칸 위치
    pair<int,int> p = blank[depth];

    // 1~9 까지 채워보기
    for(int i = 1 ; i <= 9 ; i++){
        sudoku[p.first][p.second] = i;  // 채우기
        if(isAble(p)) dfs(depth + 1);   // 만약 n 사용할 수 있으면 다음 칸 채우러

        if(clear) return;               // 만약에 클리어 했으면 return
        sudoku[p.first][p.second] = 0;  // 회수
    }
}

int main(){
    // input
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin >> n;
            if(n == 0) blank.push_back({i,j});
            sudoku[i][j] = n;
        }
    }

    dfs(0);

    // output
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}