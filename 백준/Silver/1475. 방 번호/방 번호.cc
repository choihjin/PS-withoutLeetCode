#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v(10);
  string num;
  cin >> num;

  for(int i=0; i<num.size(); i++) {
    if(int(num[i])-48 == 6 || int(num[i])-48 == 9) {
      v.at(6)++;
    } else {
      v.at(int(num[i])-48)++;
    }
  }
  v[6] = v[6] / 2 + v[6] % 2;
  
  int max = 0;
  for(int i=1; i<9; i++) {
    if(v[i] > v.at(max)) max = i;
  }
  cout << v.at(max) << endl;
  
  return 0;
}