#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;

        stack<char> S;
        bool check = true;
        for(char c : str) {
            if(c == '(') S.push(c);
            else if(c == ')') {
                if(S.empty()) {
                    check = false;
                    break;
                } else S.pop();
            }
        }
        if(S.empty() && check) cout << "YES\n";
        else cout << "NO\n";
    }
}