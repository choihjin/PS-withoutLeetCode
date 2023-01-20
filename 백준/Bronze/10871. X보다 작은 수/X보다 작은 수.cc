#include <iostream>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  
  while(n--) {
    int buffer;
    cin >> buffer;
    if(buffer < x) cout << buffer << " ";
  }
}