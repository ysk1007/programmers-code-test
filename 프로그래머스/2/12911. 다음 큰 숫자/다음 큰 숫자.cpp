#include <string>
#include <vector>
using namespace std;
//13:52
int count(int num){
    int count = 0;
    
    while(num != 0){
        count += (num%2 == 1) ? 1 : 0;
        num /= 2;
    }

    return count;
}

int solution(int n) {
    int answer = n + 1;
    int temp = count(n);
    
    while(true){
        if(count(answer) == temp) break;
        answer++;
    }
    
    return answer;
}