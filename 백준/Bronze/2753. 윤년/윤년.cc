#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool leap = false;
    int n;
    cin >> n;
    if(n % 4 == 0 && n % 100 != 0) leap = true;
    else if(n % 400 == 0) leap = true;

    cout << leap << endl;
    
    return 0;
}