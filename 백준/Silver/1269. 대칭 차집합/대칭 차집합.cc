#include<iostream>
#include<map>
using namespace std;

// 대칭 차집합 #1269

int a,b,n,result = 0;
map<int,int> mp;

int main(){
    cin >> a >> b;
    for(int i = 0 ; i < a+b ; i++){
        cin >> n;
        
        if(mp[n] > 0){mp[n]--; result--;}
        else{mp[n]++; result++;}
    }
    cout << result;

    return 0;
}