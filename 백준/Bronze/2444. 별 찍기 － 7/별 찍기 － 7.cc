#include<iostream>
#include<deque>
using namespace std;

// 별 찍기 - 7 #2444

deque<string> deq;
deque<string> blank;
int n;

void print(){
    if(deq.empty()){
        deq.push_back("*");
    }

    for(auto b : blank){
        cout << b;
    }

    for(auto d : deq){
        cout << d;
    }
    cout << "\n";
}


int main(){
    cin >> n;

    for(int i = 1 ; i < n ; i++){
        blank.push_back(" ");
    }

    for(int i = 1 ; i < 2*n-1 ; i++){
        print();
        if(i < n){
            deq.push_back("*");
            deq.push_front("*");
            blank.pop_back();
        }
        else{
            deq.pop_back();
            deq.pop_front();
            blank.push_back(" ");
        }
    }
    print();
}