#include <bits/stdc++.h>
using namespace std;

int h, m, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> m >> t;
    h += t/60;
    m += t%60;
    
    if(m > 59) {
        h++;
        m -= 60;
    }
    
    if(h > 23) h %= 24;
    
    cout << h << " " << m;
}