#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    int count = 0;
    for(auto w : s){
        if(w == 'p' || w == 'P') count += 1;
        else if(w == 'y' || w == 'Y') count -= 1;
    }
    
    return count == 0 ? true : false;
    
    //return count(s.begin(),s.end(),'p') + count(s.begin(),s.end(),'P') == 
    //       count(s.begin(),s.end(),'y') + count(s.begin(),s.end(),'Y') ?
    //       true : false;
}