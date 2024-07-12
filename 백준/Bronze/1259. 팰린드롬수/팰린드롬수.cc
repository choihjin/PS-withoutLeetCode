#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    string str;
    while(1) {
        cin >> str;
        if(str == "0") break;

        string rev = str;
        reverse(rev.begin(), rev.end());

        if(str == rev) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}