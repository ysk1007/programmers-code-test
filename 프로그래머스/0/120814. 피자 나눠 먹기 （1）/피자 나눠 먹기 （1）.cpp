#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int add = (n % 7 > 0) ? 1 : 0;
    return (n / 7) + add;
}