#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


//케빈 베이컨의 6단계 법칙 #1389
map<int,vector<int>> mp;
int n,m, a,b;

// 내가 작성한 bfs
int bfs(int i){
    int level = 0;  // 케빈 베이컨 단계

    vector<bool> visit(n+1,false);          // 방문 여부
    queue<pair<int,int>> que;               // queue {타겟 숫자, 방문 레벨}

    visit[i] = true;                        // 본인은 제외해야하니까 visit true
    for(auto j : mp[i]){                    // 본인과 친구인 숫자들 que에 넣기
        que.push({j,1});
    }

    while(!que.empty()){                    // que가 작업이 없을 때까지

        pair<int,int> temp = que.front();   // temp에 저장하고 pop
        que.pop();

        if(!visit[temp.first]){             // 방문하지 않은 숫자이면
            visit[temp.first] = true;       // 방문 체크
            level += temp.second;           // 케빈 단계 += 방문 레벨

            for(auto k : mp[temp.first]){   // 이 숫자의 친구들도 que에 넣기
                que.push({k,temp.second+1});
            }
        }
    }

    return level;   // 단계 반환
}

int main(){
    cin >> n >> m;

    // 친구 관계 init
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;

        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    
    // 가장 작은 케빈 베이컨 단계를 가진 사람 출력
    vector<int> result;
    int minCount = 999999;

    for(int i = 1 ; i <= n ; i++){
        // 모든 사람 bfs로 단계 체크
        int level = bfs(i);

        // 이 사람이 최소 단계이면 result 초기화
        if(minCount > level){
            result.clear();
            minCount = level;
            result.push_back(i);
        }
        // 동일한 단계이면 result에 넣기
        else if(minCount == level){
            result.push_back(i);
        }
    }

    // 가장 작은 수 출력
    cout << *min_element(result.begin(),result.end());
}