#include <bits/stdc++.h>
using namespace std;

int h, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> m;
    if(m >= 45) m -= 45;
    else {
        if(h >0) h--;
        else h = 23;
        m = 60-(45-m);
    }
    cout << h << " " << m;
}