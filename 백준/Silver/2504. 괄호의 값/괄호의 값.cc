#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> St;
    int buffer = 1;
    string s;
    cin >> s;

    int count = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            St.push(s[i]);
            buffer *= 2;
        } 
        else if(s[i] == '[') {
            St.push(s[i]);
            buffer *= 3;
        }
        else if(s[i] == ')') {
            if(St.empty() || St.top() != '(') {
                count = 0;
                break;
            }
            if(s[i-1] == '(') count += buffer;
            St.pop();
            buffer /= 2;
        } 
        else if(s[i] == ']') {
            if(St.empty() || St.top() != '[') {
                count = 0;
                break;
            }
            if(s[i-1] == '[') count += buffer;
            St.pop();
            buffer /= 3;
        }
    }
    if(St.size()) cout << 0 << "\n";
    else cout << count << "\n";
}