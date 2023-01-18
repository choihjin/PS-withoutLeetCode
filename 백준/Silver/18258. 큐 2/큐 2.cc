#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
	cin.sync_with_stdio(0);

  queue<int> Queue;
  int n;
  string command;

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> command;
    if(command == "push") {
      int buffer;
      cin >> buffer;
      Queue.push(buffer);
    } else if(command == "pop") {
      if(!Queue.empty()) {
        cout << Queue.front() << "\n";
        Queue.pop();
      } else {
        cout << -1 << "\n";
      }
    } else if(command == "size") {
      cout << Queue.size() << "\n";
    } else if(command == "empty") {
      cout << Queue.empty() << "\n";
    } else if(command == "front") {
      if(!Queue.empty()) cout << Queue.front() << "\n";
      else cout << -1 << "\n";
    } else if(command == "back") {
      if(!Queue.empty()) cout << Queue.back() << "\n";
      else cout << -1 << "\n";
    }
  }
  return 0;
}