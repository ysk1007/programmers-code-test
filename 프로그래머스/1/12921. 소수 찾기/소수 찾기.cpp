#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n) {
    vector<bool> b(n,true);
    for(int i = 2 ; i <= sqrt(n); i++){
        if(b[i]){
            for(int j = i*2 ; j <= n ; j += i){
                b[j] = false;
            }
        }
    }
    return count(b.begin() + 2,b.end() + 1,true);
}