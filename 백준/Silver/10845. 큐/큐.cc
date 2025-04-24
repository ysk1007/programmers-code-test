#include<iostream>
#include<queue>
using namespace std;

bool isEmpty(queue<int> q){
    bool b = q.empty();
    if(b) cout << -1 << "\n";
    return b;
}

// 큐 #10845
int main(){
    queue<int> que;
    int t,n;
    string s;

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> s;

        if(s == "push"){
            cin >> n;
            que.push(n);
        }
        else if(s == "pop" && !isEmpty(que)){
            cout << que.front() << "\n";
            que.pop();
        }

        else if(s == "size") cout << que.size() << "\n";
        else if(s == "empty") cout << (que.empty() ? 1 : 0) << "\n";
        else if(s == "front" && !isEmpty(que)) cout << que.front() << "\n";
        else if(s == "back" && !isEmpty(que)) cout << que.back() << "\n";
    }

    return 0;
}