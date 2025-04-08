#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
// 3:45
string solution(string s) {
    string answer = "";
    vector<int> num;
    stringstream ss(s);
    string str;
    while(ss >> str){
        num.push_back(stoi(str));
    }
    sort(num.begin(),num.end());
    answer += to_string(num.front()) + " " + to_string(num.back());
    return answer;
}