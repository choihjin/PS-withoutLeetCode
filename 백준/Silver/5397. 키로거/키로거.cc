#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n;
    while(n--) {
        list<char> L;
        auto cursor = L.begin();

        cin >> s;
        for(auto c : s) {
            if(c == '<') {
                if(cursor != L.begin()) cursor--;
            }
            else if(c == '>') {
                if(cursor != L.end()) cursor++;
            }
            else if(c == '-') {
                if(cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else {
                L.insert(cursor, c);
            }
        }

        for(auto i : L) cout << i;
        cout << "\n";
    }
}