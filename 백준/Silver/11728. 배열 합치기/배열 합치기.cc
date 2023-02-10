#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000002], b[1000002], c[2000004];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  int aidx = 0, bidx = 0;
  for(int i=0; i<n+m; i++) {
    if(aidx == n) c[i] = b[bidx++];
    else if(bidx == m) c[i] = a[aidx++];
    else if(a[aidx] >= b[bidx]) c[i] = b[bidx++];
    else c[i] = a[aidx++];
  }

  for(int i=0; i<n+m; i++) cout << c[i] << " ";
}