#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    string s;

    cin >> s;
    int count = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(' && s[i+1] != ')') {
            count ++;
            S.push(s[i]);
        } else if(s[i] == '(' && s[i+1] == ')') {
            count += S.size();
            i++;
        } else S.pop();
    }
    cout << count << "\n";
}