#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,string> a, pair<int,string> b)
{
    return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  pair<int, string> buffer;
  vector<pair<int, string>> v;
  while(n--) {
    cin >> buffer.first >> buffer.second;
    v.push_back(buffer);
  }
  stable_sort(v.begin(), v.end(), compare);

  for(int i=0; i<v.size(); i++) {
    cout << v[i].first << " " << v[i].second << "\n";
  }
}