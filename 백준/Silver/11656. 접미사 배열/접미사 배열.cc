#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<string> v;
  string buffer;
  for(int i=0; i<s.size(); i++) {
    buffer = s.substr(i, s.size());
    v.push_back(buffer);
  }
  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++) {
    cout << v[i] << endl;
  }
}