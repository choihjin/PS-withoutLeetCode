#include <bits/stdc++.h>
using namespace std;

int N;
string paper[70];
string res;

bool check(int a, int b, int n) {
    for(int i = a; i < a + n; i++) 
        for(int j = b; j < b + n; j++) 
            if(paper[a][b] != paper[i][j]) return false;
    return true;
}

void func(int a, int b, int n) {
    if(check(a, b ,n)) {
        res += paper[a][b];
        return;
    }
    
    res += "(";
    n /= 2;
    for(int i=0; i<2; i++) 
        for(int j=0; j<2; j++)
            func(a + i * n, b + j * n, n);

    res += ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> paper[i];

    func(0, 0, N);
    cout << res << "\n";
}