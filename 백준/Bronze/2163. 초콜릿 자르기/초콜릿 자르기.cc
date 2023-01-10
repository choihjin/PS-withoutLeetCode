#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss;
    ss.str(s);
    
    int n, m;
    ss >> n;
    ss >> m;
    
    cout << m * n - 1 << endl;
}