#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// 창문 닫기 #13909
int main(){
    int t;
    cin >> t;

    // vector<bool> vc(t,true);

    // for(int i = 2 ; i <= t ; i++){
    //     for(int j = i ; j <= t ; j += i){
    //         bool temp = vc[j - 1];
    //         vc[j - 1] = !temp;
    //     }
    // }

    // int count = 0;
    // int i = 1;
    // for(auto v : vc){
    //     if(v) count++;
    //     cout << i << "번째 : " << v << "\n";
    //     i++;
    // }

    // 구현해서 확인해 보니까 제곱수만 열려 있다.
    // 1, 4, 9, 16, 25, 36 ...
    // 1 ~ t 까지 제곱수가 몇 개 있는지 확인하면 됨

    cout << floor(sqrt(t));
}  