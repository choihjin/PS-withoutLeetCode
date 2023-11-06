#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    if(stoi(str1) > stoi(str2)) cout << str1 << endl;
    else cout << str2 << endl;

    return 0;
}