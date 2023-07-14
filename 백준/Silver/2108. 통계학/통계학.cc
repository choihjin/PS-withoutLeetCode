#include <bits/stdc++.h>
using namespace std;

int arr[500002];
int cnt[8002];

int main() {
    int n;
    int avg = 0, mid, mode, range;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        avg += arr[i];
        cnt[arr[i] + 4000]++;
    }

    sort(arr, arr+n);

    int mx = *max_element(cnt, cnt+8002);
    int first = 0;
    for(int i=0; i<8002; i++) {
        if(first == 2) break;
        if(cnt[i] == mx) {
            mode = i - 4000;
            first++;
        }
    }

    avg = round((double)avg / n);
    if(avg == -0) avg = 0;
    cout << avg << "\n";
    cout <<  arr[n / 2] << "\n";
    cout << mode << "\n";
    cout << arr[n-1] - arr[0] << "\n";

    return 0;
}