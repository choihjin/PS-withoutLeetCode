#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++){
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
  }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, p;
    getline(cin, s);
    getline(cin, p);

    vector<int> f = failure(p);
    int j = 0;
    vector<int> ans;
    for(int i=0; i<s.size(); i++) {
        while(j > 0 && s[i] != p[j]) j = f[j-1];
        if(s[i] == p[j]) j++;
        if(j == f.size()) {
            ans.push_back(i-j+2);
            j = f[j-1];
        }
    }  

    cout << ans.size() << endl;
    for(auto a : ans) 
        cout << a << " ";
    cout << endl;

    return 0;
}