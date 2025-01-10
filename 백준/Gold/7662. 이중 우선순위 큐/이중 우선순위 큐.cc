#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        multiset<int> ms;

        while (k--) {
            char cmd;
            int num;
            cin >> cmd >> num;

            // Insert
            if (cmd == 'I') 
                ms.insert(num);
            // Delete
            else if (cmd == 'D') {
                if(ms.size() == 0) continue;
                if (num == 1) { 
                    auto it = ms.find(*prev(ms.end()));
                    if (it != ms.end()) ms.erase(it);
                } else { 
                    auto it = ms.find(*ms.begin());
                    if (it != ms.end()) ms.erase(it);
                }
            }
        }
        if(ms.size() == 0) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << " " << *ms.begin() << endl;
    }

    return 0;
}
