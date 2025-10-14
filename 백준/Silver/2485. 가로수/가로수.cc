#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){          // 유클리드 호제법 (나누는 수를 나머지로 계속 바꾸면서 나머지가 0일 때까지)
    int r = 0;                  // 나머지
    
    while(true){
        r = a % b;              // a를 b로 나눈 나머지를 구한다
        if(r == 0) break;       // 나머지가 0 이면 나눈 수가 최대 공약수

        a = b;                  // 나눈수를 나누는수로
        b = r;                  // 나누는수를 나머지로
    }

    return b;
}

// 가로수 #2485
int main(){
    int t;
    cin >> t;
    
    vector<int> tree(t,0);
    vector<int> dist(t-1,0);

    for(int i = 0 ; i < t ; i++){
        cin >> tree[i];

        if(i != 0){
            // 나무 사이 간격 계산
            dist[i-1] = tree[i] - tree[i-1];
        }
    }

    // 나무들 사이의 거리를 일정하게 만들 간격을 구하기
    int totalDist = dist[0];
    for(int i = 1 ; i < t-1 ; i++){
        // 모든 간격들 사이에 최대공약수를 구하면 된다
        totalDist = gcd(totalDist, dist[i]);
    }

    // 간격 안의 나무 갯수 = (간격 길이(종료 위치 - 시작 위치) / 최종 간격) - 1
    // 전체 나무 갯수 = 간격 안의 나무 갯수 + 2 (시작 나무, 종료 나무)
    int totalTree = ((tree.back() - tree.front()) / totalDist) + 1;
    
    cout << totalTree - t;
}