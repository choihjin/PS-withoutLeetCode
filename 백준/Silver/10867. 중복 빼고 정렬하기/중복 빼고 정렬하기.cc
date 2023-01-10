#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v;
  int buffer;
  for(int i=0; i<n; i++) {
    cin >> buffer;

    bool check = false;
    for(int j=0; j<v.size(); j++) {
      if(buffer == v[j]) {
        check = true;
        break;
      }
    }

    if(!check) v.push_back(buffer);
  }

  sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}