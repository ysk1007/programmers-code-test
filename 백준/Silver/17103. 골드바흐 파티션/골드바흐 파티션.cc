#include<iostream>
#include<vector>

using namespace std;


// 골드바흐 파티션 #17103
int t,n;
vector<int> demical;
vector<bool> sieve(1000001,true);


void eratos(){
    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2 ; i < sieve.size() ; i++){
        if(sieve[i] == false) continue;
        demical.push_back(i);

        for(int j = i * 2 ; j < sieve.size() ; j += i){
            sieve[j] = false;
        }
    }
}


int main(){
    eratos();

    cin >> t;
    for(int i = 0 ; i < t ; i++){
        cin >> n;
        int j = 0;
        int count = 0;
        while(true){
            int num = demical[j];
            
            if(num > n/2) break;

            if(n == num * 2) count++;
            else if(sieve[n - num]) count++;

            j++;
        }
        cout << count << "\n";
    }

}