#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int N;
int a[1005];
vector<int> two;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);

    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) 
            two.push_back(a[i] + a[j]);
    }
    sort(two.begin(), two.end());

    for(int i = N-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(binary_search(two.begin(), two.end(), a[i]-a[j])) {
                cout << a[i] << endl;
                return 0;
            }
        }
    }

    return 0;
}