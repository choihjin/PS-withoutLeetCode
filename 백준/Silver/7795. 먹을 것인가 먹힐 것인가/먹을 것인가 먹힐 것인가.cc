#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[20002];
int b[20002];

bool cmp(int x, int y) {
    return x > y;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        sort(a, a+n, cmp);
        sort(b, b+m, cmp);

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i] > b[j]) {
                    cnt += m - j;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
}
