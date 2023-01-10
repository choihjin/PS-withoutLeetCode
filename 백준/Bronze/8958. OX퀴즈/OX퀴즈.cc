#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<string> v;

    string buffer;
    for(int i=0; i<num; i++) {
        cin >> buffer;
        v.push_back(buffer);
    }

    int sum = 0;
    int temp = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            if(v[i][j] == 'O' && temp == 0) {
                sum++;
                temp++;
            } else if(v[i][j] == 'O' && temp != 0) {
                sum += temp+1;
                temp++;
            } else {
                temp = 0;
            }
        }
        cout << sum << endl;
        sum = 0;
        temp = 0;
    }
}