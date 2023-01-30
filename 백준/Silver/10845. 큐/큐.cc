#include <bits/stdc++.h>
using namespace std;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  
  int n;
  queue<int> Q;
  
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    if(s == "push") {
      int buffer;
      cin >> buffer;
      Q.push(buffer);
    } 
    else if(s == "pop") {
      if(Q.empty()) cout << -1 << "\n";
      else {
        cout << Q.front() << "\n";
        Q.pop();
      }
    } 
    else if(s == "size") cout << Q.size() << "\n";
    else if(s == "empty") cout << Q.empty() << "\n";
    else if(s == "front") {
      if(Q.empty()) cout << -1 << "\n";
      else {
        cout << Q.front() << "\n";
      }
    }
    else if(s == "back") {
      if(Q.empty()) cout << -1 << "\n";
      else {
        cout << Q.back() << "\n";
      }
    }
  }
}