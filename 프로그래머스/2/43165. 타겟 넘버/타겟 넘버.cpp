#include <string>
#include <vector>

using namespace std;

vector<int> vc;
int depth = 0;
int answer = 0;
int t = 0;

void dfs(int r, int d){
    if(d == depth){
        if(r == t){answer++;}
    }
    else{
        dfs(r-vc[d],d + 1);
        dfs(r+vc[d],d + 1);
    }
}

int solution(vector<int> numbers, int target) {
    depth = numbers.size();
    vc = numbers;
    t = target;
    dfs(0,0);
    return answer;
}