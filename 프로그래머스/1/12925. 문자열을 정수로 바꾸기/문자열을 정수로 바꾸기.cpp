#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    return stoi(s);
    return (s[0] == '-') ? stoi(s.substr(1)) * -1 : stoi(s.substr(0));
}