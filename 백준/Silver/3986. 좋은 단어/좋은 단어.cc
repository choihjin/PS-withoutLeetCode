#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int count = 0;
    while(n--) {
        string s;
        cin >> s;
    
        stack<char> S;
        for(char c : s) {
            if(!S.empty() && S.top() == c) S.pop();
            else S.push(c); 
        }
        if(S.empty()) count++;
    }
    cout << count << "\n";
}