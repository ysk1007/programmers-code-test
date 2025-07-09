#include<iostream>
#include<vector>
using namespace std;

// 스타트와 링크 #14889

int t;
vector<vector<int>> vc;
bool visited[22];
int result = 99999;

// 재귀함수
void dfs(int index, int depth){
    if(depth == t/2){   // 한 팀 다 뽑음

        // 팀 세팅
        vector<int> team, other;

        for(int i = 0 ; i < t ; i++){
            if(visited[i]) team.push_back(i); // 방문한 팀은 team 
            else other.push_back(i);          // 방문 안 한팀은 자동으로 other
        }

        int teamScore = 0, otherScore = 0, diff = 0;

        // 팀 능력치 계산
        for(int j = 0 ; j < t/2 ; j++){
            for(int k = 0 ; k < t/2 ; k++){
                if(j == k) continue;
                teamScore += vc[team[j]][team[k]];
                otherScore += vc[other[j]][other[k]];
            }
        }

        // 능력치 차이 계산해서 최소면 저장
        result = min(result, abs(teamScore - otherScore));
        return;
    }

    // 아직 한 팀 다 안 뽑음
    for(int i = index ; i < t ; i++){
        // 이전 선택보다 오른쪽에 있는 사람을 고르게 하므로 중복 팀이 발생하지 않음
        // index = 0 -> 1,2,3 -> (0,1), (0,2), (0,3)
        // index = 1 -> 2,3 -> (1,2), (1,3)
        // index = 2 -> 3 -> (2,3)

        visited[i] = true;              // i 번째 사람 뽑았음
        dfs(i+1,depth+1);               // 다음 사람 뽑으러
        visited[i] = false;             // i 번째 사람 회수
    }
}

int main(){
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // input
    cin >> t;
    vc = vector<vector<int>>(t,vector<int>(t));
    for(int i = 0 ; i < t ; i++){
        for(int j = 0 ; j < t ; j++){
            cin >> vc[i][j];
        }
    }

    // 함수 호출
    dfs(0,0);

    // output
    cout << result;
    return 0;
}