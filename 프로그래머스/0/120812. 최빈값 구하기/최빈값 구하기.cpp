#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    map<int,int> tmp;
    int answer = 0;
    int max_value = 0;
    
    for(const auto num : array){
        tmp[num]++;
    }
    
    for(const auto& index : tmp){
        if(index.second > max_value){
            answer = index.first;
            max_value = index.second;
        }
        else if (index.second == max_value)
            answer = -1;
    }
    return answer;
}