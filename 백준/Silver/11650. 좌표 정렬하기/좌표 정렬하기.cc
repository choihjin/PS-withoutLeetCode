#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  vector<vector<int>> v;
  
  cin >> n;

  vector<int> buffer;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    buffer.push_back(a);
    buffer.push_back(b);
    v.push_back(buffer);
    buffer.clear();
  }

  sort(v.begin(), v.end());
  for(auto a : v) {
    cout << a[0] << " " << a[1] << "\n";
  }

  return 0;
}