#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = {0,0};
    for(int i = 0 ; i < num_list.size() ; i++){
        answer[num_list[i] % 2]++;
    }
    
    return answer;
}