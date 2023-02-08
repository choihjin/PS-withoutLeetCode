#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    string s = to_string(b);
    
    cout << a * (s[2]-'0') << "\n";
    cout << a * (s[1]-'0') << "\n";
    cout << a * (s[0]-'0') << "\n";
    cout << a * b << "\n";
}