#include <string>
#include <vector>
#include <numeric>
using namespace std;
// 00:49
int solution(vector<int> arr) {
    int answer = 1;
    
    for(auto a : arr){ answer = lcm(a,answer); }
    
    return answer;
}