#include <string>
#include <vector>
using namespace std;
// 49:00 # https://school.programmers.co.kr/questions/24730 해설과 gpt 활용해서 해결
vector<int> solution(int n, long long k) {
    vector<int> num;
    vector<int> answer;
    vector<long long> fac = {1,1,2};
    
    for(int i = 1 ; i <= n ; i++){
        num.push_back(i);
    }
    
    for(int i = 3 ; i <= n ; i++){
        fac.push_back(fac.back() * i);
    }
    
    k--;
    while(n){
        answer.push_back(num[(k)/fac[n-1]]);
        num.erase(num.begin() + (k)/fac[n-1]);
        k %= fac[n-1];
        n--;
    }
    
    return answer;
}