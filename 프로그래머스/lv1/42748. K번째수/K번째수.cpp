#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++) {
        int start = commands[i][0]-1;
        int end = commands[i][1]-1;

        vector<int> v;
        copy(array.begin() + start, array.begin() + end + 1, back_inserter(v));
        sort(v.begin(), v.end());
        
        int buffer = v.at(commands[i][2]-1);
        answer.push_back(buffer);
    }
    
    return answer;
}