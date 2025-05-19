#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m, l, p, diff;
int probLevel[100'002];     // 이 문제가 어느 난이도였는지 저장
set<int> probByLevel[102];  // 난이도별로 문제 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> p >> l;
        probLevel[p] = l;
        probByLevel[l].insert(p);
    }

    cin >> m;
    while(m--) {
        string op;
        cin >> op;

        if (op == "recommend") {
            cin >> diff;
            
            // hard
            if(diff == 1) {
                for(int i = 100; i >= 0; i--) {
                    if (probByLevel[i].empty()) continue;
                    cout << *prev(probByLevel[i].end()) << endl;
                    break;
                }
            }
            // easy
            else {
                for(int i = 0; i <= 100; i++) {
                    if (probByLevel[i].empty()) continue;
                    cout << *probByLevel[i].begin() << endl;
                    break;
                }
            }
        }
        else if (op == "add") {
            cin >> p >> l;
            probLevel[p] = l;
            probByLevel[l].insert(p);
        }
        else if (op == "solved"){
            cin >> p;
            probByLevel[probLevel[p]].erase(p);
        }
    }

    return 0;
}