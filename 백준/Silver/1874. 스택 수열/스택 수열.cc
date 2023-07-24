#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> S;
    int cnt = 1;
    string res;
    while(n--){
        int buffer;
        cin >> buffer;

        while(cnt <= buffer) {
            S.push(cnt++);
            res += "+\n";
        }
        
        if(S.top() != buffer) {
            cout << "NO\n";
            return 0;
        }

        S.pop();
        res += "-\n";
    }

    cout << res;
    return 0;
}