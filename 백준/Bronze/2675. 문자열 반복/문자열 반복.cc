#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string buffer;
        cin >> n >> buffer;
        for(int i=0; i<buffer.size(); i++) {
            for(int j=0; j<n; j++)
                cout << buffer[i];
        }
        cout << "\n";
    }
    
    return 0;
}