#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> stack;
  int n;
  cin >> n;

  string s;
  for(int i=0; i<n; i++) {
    cin >> s;
    if(s == "push") {
      int buffer;
      cin >> buffer;
      stack.push(buffer);
    } else if(s == "pop") {
      if(!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
      } else {
        cout << -1 << endl;
      }
    } else if(s == "size") {
      cout << stack.size() << endl;
    } else if(s == "empty") {
      cout << stack.empty() << endl;
    } else if(s == "top") {
      if(!stack.empty()) {
        cout << stack.top() << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  
  return 0;
}