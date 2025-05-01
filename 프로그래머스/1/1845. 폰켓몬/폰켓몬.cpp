#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int,int> m;
    for(auto n : nums){
        m[n]++;
    }
    return min(m.size(),nums.size()/2);
}