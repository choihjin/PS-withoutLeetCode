#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, k;
int arr[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++) arr[j]++;
    }

    int en = 0;
    int tot = arr[0];
    for(int st = 0; st < 1000000; st++) {
        while(tot < k && en < 1000000) {
            en++;
            if (en != 1000000) tot += arr[en];
        }

        if (en == 1000000) break;

        if (tot == k) {
            cout << st << " " << en + 1 << endl;
            return 0;
        }

        tot -= arr[st];
    }

    cout << 0 << ' ' << 0;
    return 0;
}