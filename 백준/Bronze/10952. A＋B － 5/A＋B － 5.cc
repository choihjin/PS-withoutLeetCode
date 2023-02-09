#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        cout << a+b << "\n";
    }
}