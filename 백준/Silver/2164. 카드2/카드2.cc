#include<iostream>
#include<queue>
using namespace std;

// 카드2 #2164
int main(){
    int t;
    cin >> t;
    queue<int> qe;
    
    for(int i = 1 ; i <= t ; i++){
        qe.push(i);
    }

    while(qe.size() > 1){
        qe.pop();
        int temp = qe.front();
        qe.pop();
        qe.push(temp);
    }

    cout << qe.front();

    return 0;
}