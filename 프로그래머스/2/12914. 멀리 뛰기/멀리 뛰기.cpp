#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 피보나치 수열 나무위키 참조
// https://namu.wiki/w/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98%20%EC%88%98%EC%97%B4

// n개의 경우의 수 = (n - 1)개의 경우의 수 + (n - 2)개의 경우의 수
// 계단 n개를 오르는 경우의 수는 마지막에 한 계단을 오르는 경우와 마지막에 두 계단을 오르는 경우로 나누어 구할 수 있다

long long solution(int n) {
    long long answer = 0;   //n개의   경우의 수
    long long prev1 = 1;    //n-2개의 경우의 수
    long long prev2 = 2;    //n-1개의 경우의 수
    
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    for(int i = 3 ; i <= n ; i++){
        answer = (prev2 + prev1) % 1234567LL;
        prev1 = prev2;
        prev2 = answer;
    }
    
    return answer;
}