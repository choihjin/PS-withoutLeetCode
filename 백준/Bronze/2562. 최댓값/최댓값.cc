#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int max = 0;
  int index;
  for(int i=0; i<9; i++) {
    int buffer;
    cin >> buffer;
    if(max < buffer) {
      max = buffer;
      index = i+1;
    }
  }

  cout << max << "\n" << index;
}