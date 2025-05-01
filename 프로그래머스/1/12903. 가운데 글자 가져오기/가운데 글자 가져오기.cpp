#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int c = s.size()/2;
    return s.size() & 1 ? s.substr(c,1):s.substr(c - 1, 2);
}