#include<iostream>

using namespace std;

// 주유소 #13305
int main(){
    long long t, n, pos = 0, oil = 0, result = 0;

    cin >> t;

    long long dis[t-1];
    long long amount[t];
    long long minAmount = 1000000001;

    for(int i = 0 ; i < t-1 ; i++){
        cin >> dis[i];
    }
    
    for(int i = 0 ; i < t-1 ; i++){
        cin >> n;
        amount[i] = n;
        minAmount = min(n, minAmount);
    }

    while(pos != t-1){
        // 만약 현재 주유소가 최저라면 여기서 다 넣어도 되지 않을까
        if(amount[pos] == minAmount){

            // 남은 거리
            int d = 0;
            for(int i = 0 ; i < t - pos - 1 ; i++){
                d += dis[pos + i];
            }

            result += (d - oil) * minAmount;

            cout << result;
            return 0;
        }

        // 만약 지금 가지고 있는 기름으로도 갈 수 있음
        if(oil >= dis[pos]){
            oil -= dis[pos];
        }
        else{
            int a = amount[pos];

            // 다음까지 갈 수 있는 최소양은 넣어야 함
            while(oil < dis[pos]){
                oil++;
                result += a;
            }

            // 지금 주유소 가격이 앞으로 나올 주유소 가격보다 싸면 미리 넣자
            for(int i = 1 ; i < t - pos - 1 ; i++){
                if(a < amount[pos + i]){
                    oil += dis[pos + i];
                    result += dis[pos + i] * a;
                }
                else{
                    break;
                }
            }
            
            oil -= dis[pos];
        }
        pos++;
    }


    cout << result;
}        