#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// 소수 구하기 #1929

int m,n;
vector<bool> vc;

// 에라토스테네스의 체
void eratosthenes(){
    vc[0] = false;  // 0 제외
    vc[1] = false;  // 1 제외

    for(int i = 2 ; i <= sqrt(n); i++){
        if(vc[i]){ // 소수라면
            for(int j = i * i ; j <= n ; j += i){   // 소수들의 배수들을 미리 제외
                vc[j] = false;
            }
        }
    }

    for(int i = m ; i <= n ; i++){
        if(vc[i]) cout << i << "\n";
    }
}

int main(){

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    vc = vector<bool>(n + 1,true);

    eratosthenes();
}