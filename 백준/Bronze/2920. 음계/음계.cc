#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    stringstream ss;
    vector<int> v;
    int num;

    //tokenize
    getline(cin, input);
    ss.str(input);
    while(ss >> num) v.push_back(num);

    //check ascending
    bool ascending = false;
    for(int i=0; i<v.size(); i++) {
        if(v[i] == i+1) {
            ascending = true;
        } else {
            ascending = false;
            break;
        }
    }

    //check descending
    bool descending = false;
    for(int i=v.size()-1; i>=0; i--) {
        if(v[v.size()-i-1] == i+1) {
            descending = true;
        } else {
            descending = false;
            break;
        }
    }

    if(ascending) cout << "ascending" << endl;
    else if(descending) cout << "descending" << endl;
    else cout << "mixed" << endl;
}