#include <string>
#include <vector>
//#include <algorithm>
using namespace std;

string solution(string my_string, string letter) {
    while(true){
        if(my_string.find(letter,0) == string::npos)
            break;
        else
            my_string.erase(my_string.find(letter,0),1);
    }
    
    // 1. my_string을 처음부터 끝까지 탐색하여 remove로 특정 문자를 가장 뒤로 옮김 ex. apple -> alepp
    // 2. erase로 옮긴 인덱스 부터 끝까지 지움 alepp -> ale
    //my_string.erase(remove(my_string.begin(),my_string.end(),letter[0]),my_string.end());
    
    return my_string;
}