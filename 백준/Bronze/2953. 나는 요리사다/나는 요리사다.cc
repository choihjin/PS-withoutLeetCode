#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    vector<int> score;
    for(int i=0; i<5; i++) {
        string s;
        stringstream ss;
        getline(cin, s);
        ss.str(s);

        int buffer;
        int total = 0;
        while(ss >> buffer) total += buffer;

        score.push_back(total);
    }

    int index;
    int max = 0;
    for(int i=0; i<5; i++) {
        if(max < score[i]) {
            max = score[i];
            index = i+1;
        }
    }

    cout << index << " " << max << endl;
}