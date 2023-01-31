#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(1) {
        stack<char> S;
        getline(cin, s);
        if(s == ".") break;

        bool check = true;
        for(char c : s) {
            if(c == '(' || c == '[') {
                S.push(c);
            }
            else if(c == ')' || c == ']') {
                if(S.empty()) {
                    check = false;
                    break;
                } 
                else if(c == ')' && S.top() == '(') S.pop();
                else if(c == ']' && S.top() == '[') S.pop();
                else {
                    check = false;
                    break;
                }
            }
        }

        if(!S.empty() || !check) cout << "no\n";
        else cout << "yes\n";
    }
}