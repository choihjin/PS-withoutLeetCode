#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10];
    int sum = 0;
    for(int i=0; i<9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+9);

    for(int i=0; i<8; i++) {
        for(int j=i+1; j<9; j++) {
            if(sum - (arr[i] + arr[j]) == 100) {
                for(int h=0; h<9; h++) {
                    if(h != i & h != j) cout << arr[h] << "\n";
                }
                return 0;
            }
        }
    }

    return 0;
}