#include <string>
#include <vector>
using namespace std;
// 11:10 # 테케 성공 (제한 사항 2번 확인 안 함)
// 12:47 # 제한 사항 2번 추가
int solution(int n) {
    vector<long long> count = {1,2};
    
    for(int i = 2 ; i < n ; i++){
        count.push_back((count[i - 1] + count[i - 2]) % 1000000007LL);
    }
    
    return count[n - 1];
}