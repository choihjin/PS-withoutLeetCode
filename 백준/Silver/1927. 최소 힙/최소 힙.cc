#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

priority_queue<int, vector<int>, greater<int> > Q;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        int buffer;
        cin >> buffer;
        if(!buffer) {
            if(!Q.empty()) {
                cout << Q.top() << endl; Q.pop();
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            Q.push(buffer);
        }
    }

    return 0;   
}