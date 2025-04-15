#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 블랙잭 #2798
int main(){
    int n,m;    // 카드수, 목표 점수
    vector<int> cards;
    vector<int> score;

    // 변수 받기
    cin >> n >> m;
    while(n--){
        int c;
        cin >> c;
        cards.push_back(c);
    }

    // 모든 경우의 수
    for(int i = 0 ; i < cards.size() - 2 ; i++){
        for(int j = i + 1; j < cards.size() - 1 ; j++){
            for(int k = j + 1; k < cards.size() ; k++){
                int sc = cards[i] + cards[j] + cards[k];
                if(sc > m) continue;        // 점수 오버
                if(sc == m){                // 점수 동일
                    cout << m;
                    return 0;
                }
                score.push_back(sc);
            }
        }
    }

    // 정렬렬
    sort(score.begin(),score.end());

    cout << score.back();

    return 0;
}