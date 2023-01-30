#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n ,m;
  cin >> n >> m;

  deque<int> D;
  for(int i=0; i<n; i++) D.push_back(i+1);
  
  int count = 0;
  while(m--) {
    int buffer;
    cin >> buffer;
    
    if(buffer == D[0]) D.pop_front();
    else {
      int i;
      for(i=0; i<D.size(); i++) if(buffer == D[i]) break;

      if(i <= D.size()/2) {
        while(D[0] != buffer) {
          D.push_back(D.front());
          D.pop_front();
          count++;
        }
      } else {
        while(D[0] != buffer) {
          D.push_front(D.back());
          D.pop_back();
          count++;
        }
      }
      D.pop_front();
    }
  }
  cout << count;
}