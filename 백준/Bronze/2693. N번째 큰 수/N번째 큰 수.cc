#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v;
  for(int i=0; i<n; i++) {
    int buffer;
    for(int j=0; j<10; j++) {
      cin >> buffer;
      v.push_back(buffer);
    }
    
    sort(v.begin(), v.end());
    cout << v[7] << endl;
    v.clear();
  }
}