#include<iostream>
#include<vector>
using namespace std;

// 정수 삼각형 #1932
int t,n;

int main(){
    cin >> t;

    vector<int> vc(t,0);
    cin >> vc[0];

    for(int i = 1; i < t; i++){

        vector<int> prev(t,0);
        for(int j = 0 ; j < i ; j++){
            prev[j] = vc[j];
        }

        for(int k = 0 ; k < i + 1 ; k++){
            cin >> n;
            if(k-1 < 0) vc[k] = prev[k] + n;
            else if(k + 1 >= t) vc[k] = prev[k-1] + n;
            else{
                vc[k] = max(prev[k],prev[k-1]) + n;
            }
        }
    }

    int result = 0;
    for(auto v : vc){
        result = max(result,v);
    }

    cout << result;

    return 0;
}