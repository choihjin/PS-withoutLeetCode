#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int  buffer, n, m, mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> buffer;
            if(buffer >= mx) {
                mx = buffer;
                n = i+1;
                m = j+1;
            }
        }   
    }

    cout << mx << endl << n << " " << m << endl;

    return 0;
}