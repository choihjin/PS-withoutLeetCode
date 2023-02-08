#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10]; // 0-indexed

void func(int k) { // 현재 k개까지 수를 택했음.
    if(k == m) { // m개를 모두 택했으면
        for(int i=0; i<m; i++) cout << arr[i] << " "; // arr에 기록해둔 수를 출력
        cout << "\n";
        return;
    }

    for(int i = arr[k-1]+1; i <= n; i++){ // 이전의 수 arr[k-1] 이후부터 n까지의 수에 대해
        arr[k] = i; // k번째 수를 i로 정함
        func(k+1); // 다음 수를 정하러 한 단계 더 들어감
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}