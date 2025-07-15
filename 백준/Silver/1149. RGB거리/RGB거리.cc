#include<iostream>

using namespace std;

// RGB거리 #1149
int main(){
    int t,n;
    int result[3] = {0};
    int nums[3] = {0};

    cin >> t;
    
    for(int i = 0 ; i < t ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin >> nums[j];
        }

        int temp0 = nums[0] + min(result[1],result[2]);
        int temp1 = nums[1] + min(result[0],result[2]);
        int temp2 = nums[2] + min(result[0],result[1]);

        result[0] = temp0;
        result[1] = temp1;
        result[2] = temp2;
    }

    cout << min(min(result[0],result[1]),result[2]);
}