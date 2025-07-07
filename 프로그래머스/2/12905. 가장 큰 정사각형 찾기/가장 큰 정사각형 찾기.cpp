#include <vector>
#include <cmath>

// 37:21 # 실패
// 20:17 # 푸는 알고리즘 찾은 후 다시
// dp 문제 # https://soobarkbar.tistory.com/164

// 현재 위치 board[i][j] 가 1일때 왼쪽,위,대각선 중 최소값 +1 한 것이 정사각형 크기임
// 만약 하나라도 0이면 1 -> 즉, 자기 자신만 정사각형
// 전부 1이면 2 -> 즉, 자기 자신까지 합해서 정사각형이 됨
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    for(int i = 0 ; i < board.size(); i++){
        for(int j = 0 ; j < board[i].size(); j++){
            if(i > 0 && j > 0 && board[i][j] == 1)
                board[i][j] = min(board[i-1][j-1],min(board[i-1][j],board[i][j-1])) + 1;
            answer = answer > board[i][j] ? answer : board[i][j];
        }
    }
    
    return pow(answer,2);
}