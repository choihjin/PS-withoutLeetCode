#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1;

    str2 = str1;
    reverse(str1.begin(), str1.end());

    cout << (str1==str2) << endl;

    return 0;
}