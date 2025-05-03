#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);
    return pow(answer,2) == n ? pow(answer+1,2) : -1;
}