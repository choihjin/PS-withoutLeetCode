#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int card[105];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> card[i];

    int ans = 0;
    for(int i=0; i<n; i++) 
        for(int j=i+1; j<n; j++) 
            for(int k=j+1; k<n; k++) 
                if(card[i]+card[j]+card[k] <= m) 
                    ans = max(ans, card[i]+card[j]+card[k]);
    
    cout << ans << endl;

    return 0;
}