#include<iostream>
#include<deque>
using namespace std;

deque<pair<int,int>> deq;
pair<int,int> temp;

void pop_front(){
    temp = deq.front();
    deq.pop_front();
    cout << temp.first << " ";
}

void pop_back(){
    temp = deq.back();
    deq.pop_back();
    cout << temp.first << " ";
}

void pass_front(){
    pair<int,int> p = deq.front();
    deq.pop_front();
    deq.push_back(p);
}

void pass_back(){
    pair<int,int> p = deq.back();
    deq.pop_back();
    deq.push_front(p);
}

// 풍선 터뜨리기 #2346
int main(){
    int t,n;

    cin >> t;

    // 풍선 초기화
    for(int i = 1 ; i <= t ; i++){
        cin >> n;
        deq.push_back({i,n});
    }

    // 1번 풍선 터뜨리고 시작
    pop_front();

    while(!deq.empty()){

        // 풍선 안에 종이 숫자
        int cnt = temp.second;

        if(cnt > 0){
            // 숫자 만큼 넘기기
            for(int j = 0 ; j < cnt - 1; j++){
                pass_front();
            }

            // 풍선 터뜨리기
            pop_front();
        }
        else{
            // 숫자 만큼 넘기기
            cnt *= -1;
            for(int j = 0 ; j < cnt - 1; j++){
                pass_back();
            }

            // 풍선 터뜨리기
            pop_back();
        }
    }

    return 0;
}