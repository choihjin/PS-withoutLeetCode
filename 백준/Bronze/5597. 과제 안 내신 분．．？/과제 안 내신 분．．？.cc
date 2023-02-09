#include <bits/stdc++.h>
using namespace std;

bool arr[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 28;
    while(n--) {
        int buffer;
        cin >> buffer;
        arr[buffer-1] = 1;
    }
    
    for(int i=0; i<30; i++) {
        if(!arr[i]) cout << i+1 << "\n";
    }
}