#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 3;
    while(n--) {
        int count = 0;
        for(int i=0; i<4; i++) {
            int buffer;
            cin >> buffer;
            if(buffer == 0) count++;
        }

        if(count == 0) cout << "E" << "\n";
        else if(count == 1) cout << "A" << "\n";
        else if(count == 2) cout << "B" << "\n";
        else if(count == 3) cout << "C" << "\n";
        else if(count == 4) cout << "D" << "\n";
    }

    return 0;
}