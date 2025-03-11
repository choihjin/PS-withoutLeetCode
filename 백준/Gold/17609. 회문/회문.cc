#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int T;
int r, l;

bool is_palindrome(string tmp) {
    l = 0;
    r = tmp.size()-1;
    while(l < r) {
        if(tmp[l] != tmp[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        int ans = 2;

        string input;
        cin >> input;

        // palindrome
        if(is_palindrome(input)) ans = 0;
        // pseudo palindrome
        else {
            int tr = r, tl = l;
            string tmp = input.substr(0, tl) + input.substr(tl + 1);
            if(is_palindrome(tmp)) ans = 1;
            tmp = input.substr(0, tr) + input.substr(tr + 1);
            if(is_palindrome(tmp)) ans = 1;
        }

        cout << ans << endl;
    }

    return 0;
}