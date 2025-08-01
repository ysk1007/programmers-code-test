#include<iostream>
#include<queue>
using namespace std;

// 최대힙 #11279
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t,n;
    priority_queue<long long, vector<long long>> pq;
    cin >> t;

    while(t--){
        cin >> n;
        
        if(n == 0){
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

    return 0;
}