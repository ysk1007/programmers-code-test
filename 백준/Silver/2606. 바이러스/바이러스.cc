#include<iostream>
#include<vector>
#include<map>
using namespace std;

// 바이러스 #2606
int s,t,a,b, result = 0;
vector<bool> visited(101);
map<int,vector<int>> m;

int dfs(int i){
    if(visited[i]) return 0;
    visited[i] = true;

    int count = 1;

    for(auto next : m[i]){
        count += dfs(next);
    }

    return count;
}

int main(){
    cin >> s >> t;

    while(t--){
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);  // 양방향이기 때문에 반대로도 넣어주기..
    }

    result = dfs(1) - 1;    // 1번 컴퓨터는 제외

    cout << result;
}