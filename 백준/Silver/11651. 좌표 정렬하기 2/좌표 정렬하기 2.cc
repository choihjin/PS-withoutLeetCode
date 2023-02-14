#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  vector<pair<int, int>> v;
  
  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> a >> b;
    v.push_back({b, a});
  }

  sort(v.begin(), v.end());
  for(auto a : v) {
    cout << a.second << " " << a.first << "\n";
  }

  return 0;
}