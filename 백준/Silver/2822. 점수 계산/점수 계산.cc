#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  vector<int> v2;
  for(int i=0; i<8; i++) {
    int buffer;
    cin >> buffer;
    v.push_back(buffer);
    v2.push_back(buffer);
  }
  sort(v.begin(), v.end());

  int total = 0;
  vector<int> s;
  for(int i=3; i<8; i++) {
    total += v[i];
    for(int j=0; j<8; j++) {
      if(v[i] == v2[j]) s.push_back(j+1);
    }
  } 

  cout << total << endl;

  sort(s.begin(), s.end());
  for(int i=0; i<5; i++) {
    cout << s[i] << " ";
  }
  cout << endl;
}