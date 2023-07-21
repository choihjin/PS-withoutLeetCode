#include <bits/stdc++.h>
using namespace std;

int main() {
    string buffer;
    stringstream ss;
    
    getline(cin, buffer);
    ss.str(buffer);
    
    int cnt = 0;
    while(ss >> buffer) cnt++;
    
    cout << cnt << "\n";
}