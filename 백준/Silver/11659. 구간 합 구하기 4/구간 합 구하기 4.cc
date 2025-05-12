#include<iostream>
#include<vector>
using namespace std;

// 구간 합 구하기 4 #11659

vector<long long> vc;
int n,m,i,j,num;

int main(){
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vc = vector<long long>(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> num;
        vc[i] = num + vc[i-1];
    }

    while(m--){
        cin >> i >> j;
        cout << vc[j] - vc[i-1] << "\n";
    }

    return 0;
}