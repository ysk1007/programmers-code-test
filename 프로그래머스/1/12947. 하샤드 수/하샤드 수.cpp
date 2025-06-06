#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int i = 0;
    for(auto s : to_string(x)){
        i += s - '0';
    }
    return x % i == 0 ? true : false;
}