#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, r1, x2, y2, r2;
    int n;

    cin >> n;
    while(n--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
        int cond1 = (r1-r2) * (r1-r2);
        int cond2 = (r1+r2) * (r1+r2);

        if(dist == 0) {
            // 같은 원일 때
            if(cond1 == 0)
                cout << "-1" << '\n';
            // 작은 원이 큰 원 내부에 있고, 접하지 않을 때
            else
                cout << "0" << '\n';
        }
        // 한 점에서 접할 때 (외접 or 내접)
        else if (dist == cond1 || dist == cond2)
            cout << "1" << '\n';
        // 두 점에서 접할 때
        else if (cond1 < dist && dist < cond2)
            cout << "2" << '\n';
        // 접하지 않을 때
        else
            cout << "0" << '\n';
    }

    return 0;
}