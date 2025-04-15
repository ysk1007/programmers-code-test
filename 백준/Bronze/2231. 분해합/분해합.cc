#include<iostream>

using namespace std;

int sum(int n){
    int result = 0;
    while(n > 0){
        result += n % 10;
        n /= 10;
    }
    return result;
}

// 분해합 #2231
int main(){
    int n,result = 0;
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        if(n == i + sum(i)){
            result = i; 
            break;
        }
    }

    cout << result;
    return 0;
}