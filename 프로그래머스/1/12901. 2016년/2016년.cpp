#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> date = { 31,29,31,30,31,30,31,31,30,31,30 };
    vector<string> week = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int diff = b - 1;
    for(int i = 1 ; i < a ; i++){
        diff += date[i-1];
    }
    return week[(5 + diff%7 < week.size() ? 5 + diff%7: 5 + diff%7 - week.size())];;
}