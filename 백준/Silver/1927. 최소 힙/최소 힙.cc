#include<iostream>
#include<queue>
using namespace std;

// 최소힙 #1927
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    cin >> t;
    
    while(t--){
        cin >> n;

        if(n==0){
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(n);
        }
    }

}