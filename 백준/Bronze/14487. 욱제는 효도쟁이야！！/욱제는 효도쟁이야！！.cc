#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int buffer;
  int count = 0;
  vector<int> v;
  
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> buffer;
    v.push_back(buffer);
  }
  
  sort(v.begin(), v.end());
  for(int i=0; i<v.size()-1; i++) {
    count += v[i];
  }

  cout << count << endl;
}