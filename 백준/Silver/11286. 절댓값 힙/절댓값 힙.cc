#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct cmp {
  bool operator()(int a, int b) {
    int a2 = a, b2 = b;
    if(a2 < 0) a2 *= -1;
    if(b2 < 0) b2 *= -1;

    if(a2 != b2) return a2 > b2;
    else return a > b;
  }
};

priority_queue<int, vector<int>, cmp> Q;

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
            // cout << "Top : " << Q.top() << endl;
        }
    }

    return 0;   
}