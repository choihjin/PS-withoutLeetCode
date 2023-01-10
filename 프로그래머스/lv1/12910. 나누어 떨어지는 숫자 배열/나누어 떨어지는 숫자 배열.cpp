#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    
    //sorting
    int temp = 0;
    for(int i=answer.size()-1; i>0; i--) {
        for(int j=0; j<i; j++){
            if(answer[j] > answer[j+1]) {
                temp = answer[j];
                answer[j] = answer[j+1];
                answer[j+1] = temp;
            }
        }
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}