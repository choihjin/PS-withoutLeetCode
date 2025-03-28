#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

// CCW 함수
int ccw(pii p1, pii p2, pii p3) {
    long long cross = 1LL * p1.first * p2.second + 1LL * p2.first * p3.second + 1LL * p3.first * p1.second;
    cross -= 1LL * p1.second * p2.first + 1LL * p2.second * p3.first + 1LL * p3.second * p1.first;

    if (cross > 0) return 1;      // 반시계
    else if (cross == 0) return 0; // 일직선
    else return -1;               // 시계
}

// 선분 교차 판정 함수
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<pii, pii> a, b;

    cin >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
    cin >> b.first.first >> b.first.second >> b.second.first >> b.second.second;

    cout << isIntersect(a, b) << "\n";

    return 0;
}
