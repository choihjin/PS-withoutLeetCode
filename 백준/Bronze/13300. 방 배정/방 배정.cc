#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  int male[6]= {0, };
  int female[6] = {0, };
  
  cin >> n >> k;
  while(n--) {
    int gender;
    int grade;
    cin >> gender >> grade;
    if(gender) male[grade-1]++;
    else female[grade-1]++;
  }

  int count = 0;
  for(int i=0; i<6; i++) {
    if(male[i]%k == 0) count += male[i]/k;
    else count += male[i]/k+1;

    if(female[i]%k == 0) count += female[i]/k;
    else count += female[i]/k+1;
  }

  cout << count << "\n";
}