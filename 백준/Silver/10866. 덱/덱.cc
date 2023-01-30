#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  deque<int> D;
  
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    if(s == "push_front") {
      int buffer;
      cin >> buffer;
      D.push_front(buffer);
    }
    else if(s == "push_back") {
      int buffer;
      cin >> buffer;
      D.push_back(buffer);
    }
    else if(s == "pop_front") {
      if(D.empty()) cout << -1 << "\n";
      else {
        cout << D.front() << "\n";
        D.pop_front();
      }
    }
    else if(s == "pop_back") {
      if(D.empty()) cout << -1 << "\n";
      else {
        cout << D.back() << "\n";
        D.pop_back();
      }
    }
    else if(s == "size") cout << D.size() << "\n";
    else if(s == "empty") cout << D.empty() << "\n";
    else if(s == "front") {
      if(D.empty()) cout << -1 << "\n";
      else cout << D.front() << "\n";
    }
    else {
      if(D.empty()) cout << -1 << "\n";
      else cout << D.back() << "\n";
    }
  }
}