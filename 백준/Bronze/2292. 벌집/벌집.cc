#include<iostream>

using namespace std;

// 벌집 #2292
int main(){
    int n, result = 1;
    cin >> n;

    n -= 1;
    
    while(n > 0){
        n -= (6 * result);
        result++;
    }

    cout << result;

    return 0;
}