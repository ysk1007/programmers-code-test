#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

// solved.ac #18110

int t,n;
vector<int> vc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    if(t == 0){
        cout << 0;
        return 0;
    }

    for(int i = 0 ; i < t ; i++){
        cin >> n;
        vc.push_back(n);
    }

    sort(vc.begin(),vc.end());

    int avg = round((double)t*0.15);

    cout << round( (double)accumulate(vc.begin() + avg, vc.end() - avg, 0) / (t - avg - avg));

    return 0;
}