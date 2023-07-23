#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, buffer, res = 0;
    cin >> n;

    while(n--) {
        cin >> buffer;

        if(buffer == 1) continue;
        for(int i=2; i<buffer; i++) 
            if(buffer % i == 0) {
                res--;
                break;
            }

        res++;
    }

    cout << res << "\n";
}