#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1) return vector<int>{-1};
    
    int num = *min_element(arr.begin(),arr.end());
    arr.erase(find(arr.begin(),arr.end(),num));
    return arr;
}