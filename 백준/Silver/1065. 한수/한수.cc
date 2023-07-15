#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for(int i=1; i<=n; i++){
        string buffer = to_string(i);
        if(buffer.length() == 1) cnt++;
        else {
            int sub = buffer[1] - buffer[0];
            int flag = 0;
            for(int i=1; i<buffer.length()-1; i++) {
                if(sub != buffer[i+1] - buffer[i]) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) cnt++;
        } 
    }
    cout << cnt << "\n";

    return 0;
}