#include <bits/stdc++.h>
using namespace std;

int n;
string arr[52];

bool cmp(const string &a, const string &b) {
  // 1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
  if (a.size() != b.size())
    return a.size() < b.size();
  // 2. 숫자인 것만 더해서 작은 것이 먼저 온다.
  else {
    int acount = 0, bcount = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i] > '0' && a[i] <= '9')
        acount += a[i] - '0';
    for (int i = 0; i < b.size(); i++)
      if (b[i] > '0' && b[i] <= '9')
        bcount += b[i] - '0';
    if (acount != bcount)
      return acount < bcount;
  }
  // 3. 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
  return a < b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr+n, cmp);
  for(int i=0; i<n; i++)
    cout << arr[i] << "\n";
}