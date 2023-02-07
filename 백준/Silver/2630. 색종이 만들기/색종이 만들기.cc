#include <bits/stdc++.h>
using namespace std;

int N;
int paper[130][130];
int cnt[2]; // 0, 1로 채워진 종이 갯수

bool check(int a, int b, int n) {
    for (int i = a; i < a + n; i++)
        for (int j = b; j < b + n; j++)
            if (paper[a][b] != paper[i][j]) return false;
    return true;
}

void func(int a, int b, int n) {
    // base condition
    if(check(a, b, n)) {
        cnt[paper[a][b]]++;
        return;
    }

    n /= 2;
    for(int i=0; i<2; i++) 
        for(int j=0; j<2; j++) 
            func(a + i * n, b + j * n, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    func(0, 0, N);
    for(int i=0; i<2; i++) cout << cnt[i] << "\n";
}