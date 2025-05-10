#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arraySort(vector<int> array){
    for(int i = 0 ; i < array.size() - 1 ; i++)
        for(int j = 1 ; j < array.size() - i ; j++)
            if(array[j-1] > array[j])
                swap(array[j-1],array[j]);
    return array[(array.size() / 2)];
}

int solution(vector<int> array) {
    sort(array.begin(),array.end());
    return array[array.size() / 2];
    //return arraySort(array);
}