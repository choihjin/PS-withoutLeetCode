#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;
int n, m;
ll train[100002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while(m--) {
        int cmd, i, x;
        cin >> cmd >> i;

        if(cmd == 1) {
            cin >> x;
            train[i] |= (1LL << (x - 1));
        }
        else if(cmd == 2){
            cin >> x;
            train[i] &= ~(1LL << (x - 1));
        }
        else if(cmd == 3) {
            train[i] <<= 1;  
            train[i] &= (1LL << 20) - 1; 
        }
        else if(cmd == 4) {
            train[i] >>= 1;
        }
    }

    set<ll> galaxy;
    for(int i = 1; i <= n; i++) {
        galaxy.insert(train[i]);
    }

    cout << galaxy.size() << endl;

    return 0;
}
