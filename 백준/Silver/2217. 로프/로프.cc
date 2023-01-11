#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
  return a < b;
}

int main() {
  int n;
  vector<int> v;
  int max = 0;
  
  cin >> n;
  for(int i=0; i<n; i++) {
    int buffer;
    cin >> buffer;
    v.push_back(buffer);
  }
  sort(v.begin(), v.end(), compare);

  int buffer;
  for(int i=n-1; i>=0; i--) {
    buffer = v[i] * (n-i);
    if(max < buffer) max = buffer;
  }

  cout << max << endl;
}