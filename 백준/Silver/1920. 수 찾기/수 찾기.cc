#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<long long> a(100005);
vector<long long> target(100005);    
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    for(int i=0; i<m; i++) cin >> target[i];

    sort(a.begin(), a.begin()+n);
    for(int i=0; i<m; i++) {
        if(!binary_search(a.begin(), a.begin()+n, target[i])) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}