#include<iostream>
#include<queue>
using namespace std;

// DSLR #9019

int t,a,b;

void BFS(){
    queue<pair<int,string>> que;
    bool visited[10001] = {false};
    string str = "";
    que.push({a,str});

    while(!que.empty()){
        int temp = que.front().first;
        string s = que.front().second;

        que.pop();
        
        // 출력
        if(temp == b){
            cout << s << "\n";
            return;
        }

        // D 연산
        int next = (2 * temp) % 10000;
        if(!visited[next]){
            visited[next] = true;
            que.push({next, s + "D"});
        }
        // S 연산

        next = (temp == 0) ? 9999 : temp - 1;
        if(!visited[next]){
            visited[next] = true;
            que.push({next, s + "S"});
        }
        // L 연산

        next = (temp % 1000) * 10 + temp / 1000;
        if(!visited[next]){
            visited[next] = true;
            que.push({next, s + "L"});
        }
        // R 연산
        next = (temp/10) + ((temp % 10) * 1000);
        if(!visited[next]){
            visited[next] = true;
            que.push({next, s + "R"});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        cin >> a >> b;
        BFS();
    }
}