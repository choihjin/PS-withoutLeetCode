#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int n;
    if(a == b && b == c) n = 10000 + 1000*a;
    else if(a == b || a == c || b == c) {
        if(a == b || a == c) n = 1000 + 100*a;
        else n = 1000 + 100*b;
    } else {
        if(a >= b && a >= c) n = 100*a;
        else if(b >= a && b >= c) n =100*b;
        else n = 100*c;
    }
    cout << n << "\n";

    return 0;
}