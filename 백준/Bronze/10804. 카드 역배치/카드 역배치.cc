#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> card;
  for(int i=1; i<=20; i++) card.push_back(i);

  int n = 10;
  int a, b;
  while(n--) {
    cin >> a >> b;
    if(a != b) {
      reverse(card.begin()+a-1, card.begin()+b);
    }
  }

  for(int i=0; i<20; i++) cout << card[i] << " ";
}