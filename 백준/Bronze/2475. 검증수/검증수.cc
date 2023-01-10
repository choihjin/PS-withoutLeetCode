#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> num;
    string s;
    stringstream ss;
    int buffer;

    getline(cin, s);
    ss.str(s);
    while(ss >> buffer) num.push_back(buffer);

    int sum = 0;
    int result;
    for(int i=0; i<num.size(); i++) {
        sum += pow(num[i], 2);
    }
    result = sum % 10;

    cout << result << endl;
    return 0;
}