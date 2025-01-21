#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int e, s, m;
    cin >> e >> s >> m;

    if(s % 28 == 0) s = 0;
    if(m % 19 == 0) m = 0;
    for(int i=e; i<=7980; i+=15) {
        if(i % 28 == s && i % 19 == m) {
            cout << i << endl;
            break;
        }
    }
}