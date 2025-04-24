#include<iostream>
#include<queue>
using namespace std;

// 요세푸스 문제 0 #11866
int main(){
    int n,k;
    cin >> n >> k;
    queue<int> que;

    for(int i = 1; i <= n; i++){
        que.push(i);
    }

    cout << "<";
    while(!que.empty()){

        for(int j = 1; j < k ; j++){
            int temp = que.front();
            que.pop();
            que.push(temp);
        }

        int temp = que.front();
        que.pop();
        cout << temp << (!que.empty() ? ", ": "");
    }

    cout << ">";
    return 0;
}