#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0 ; i < arr1.size(); i++){
        int num = 0;
        vector<int> vc;
        for(int j = 0; j < arr2[0].size(); j++){
            for(int k = 0 ; k < arr1[i].size(); k++){
                num += arr1[i][k] * arr2[k][j];
            }
            vc.push_back(num);
            num = 0;
        }
        answer.push_back(vc);
    }
    
    return answer;
}