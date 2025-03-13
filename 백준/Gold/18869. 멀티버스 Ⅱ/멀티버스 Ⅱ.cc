#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int m, n;
vector<int> arr[102];
vector<int> sorted[102];
vector<int> compress[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            arr[i].push_back(tmp);
            sorted[i].push_back(tmp);
        }
    }

    for(int i = 0; i < m; i++)
        sort(sorted[i].begin(), sorted[i].end());
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            compress[i].push_back(lower_bound(sorted[i].begin(), sorted[i].end(), arr[i][j]) - sorted[i].begin());
        }
    }

    int ans = 0;
    for(int i = 0; i < m-1; i++) {
        for(int j = i+1; j < m; j++) {
            if(compress[i] == compress[j]) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}