#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 키를 넣고 정렬함
// 배열 사이즈 - 인덱스 (+1 자기자신 스킵) = 인덱스 뒤 사람들 수
int solution(vector<int> array, int height) {
    int answer = 0;
    //array.push_back(height);
    //sort(array.begin(),array.end());
    //array.erase(unique(array.begin(),array.end()), array.end());
    for(const auto i : array){
        if(i>height) answer++;
    }
    return answer;
    //return  array.size() - (find(array.begin(),array.end(),height) - array.begin() + 1);;
}