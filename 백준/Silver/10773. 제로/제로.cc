#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;

  vector<int> v;
  for(int i=0; i<k; i++) {
    int buffer;
    cin >> buffer;
    if(buffer != 0) v.push_back(buffer);
    else v.pop_back();
  }

  int total = 0;
  for(int i=0; i<v.size(); i++) {
    total += v[i];
  }
  cout << total;
}