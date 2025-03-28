#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

typedef long long ll;
pair<pii, pii> a, b;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    ll s = 1LL * p1.first * p2.second + 1LL * p2.first * p3.second + 1LL * p3.first * p1.second;
    s -= 1LL * p1.second * p2.first + 1LL * p2.second * p3.first + 1LL * p3.second * p1.first;

    if (s > 0) return 1; // 반시계
    else if (s == 0) return 0; // 일직선
    return -1; // 시계
}

bool isIntersect(pair<pii, pii> a, pair<pii, pii> b) {
    pii a1 = a.first, a2 = a.second;
    pii b1 = b.first, b2 = b.second;

    int ab = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    int ba = ccw(b1, b2, a1) * ccw(b1, b2, a2);

    if (ab == 0 && ba == 0) {
        // 정렬해서 선분이 겹치는지 확인
        if (a1 > a2) swap(a1, a2);
        if (b1 > b2) swap(b1, b2);
        return a1 <= b2 && b1 <= a2;
    }

    return ab <= 0 && ba <= 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
    cin >> b.first.first >> b.first.second >> b.second.first >> b.second.second;
    
    cout << isIntersect(a, b) << endl;

    return 0;
}