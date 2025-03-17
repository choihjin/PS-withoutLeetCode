#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n;
unordered_map<int, ll> freq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    // 고유 원소들을 모아서 정렬
    vector<int> uni;
    for (auto &p : freq)
        uni.push_back(p.first);
    sort(uni.begin(), uni.end());
    
    ll ans = 0;
    
    // [케이스 1] 세 원소 모두 같은 경우
    // a + a + a = 0 => a == 0 이어야 함.
    if(freq.count(0) && freq[0] >= 3){
        ll f = freq[0];
        ans += f * (f - 1) * (f - 2) / 6; // 조합 C(f,3)
    }
    
    // [케이스 2] 두 원소가 같은 경우
    // (a, a, b) : 조건 2*a + b = 0, 단 a와 b는 서로 달라야 하고, 중복 처리를 위해 a < b로 고정
    for (int a : uni) {
        if(freq[a] >= 2) {
            int b = -2 * a;
            if(b != a && freq.count(b) && a < b) {
                ll ways = (ll)freq[a] * (freq[a] - 1) / 2 * freq[b];
                ans += ways;
            }
        }
    }
    // (a, b, b) : 조건 a + 2*b = 0, 단 a와 b는 서로 달라야 하고, a < b로 고정
    for (int b : uni) {
        if(freq[b] >= 2) {
            int a = -2 * b;
            if(a != b && freq.count(a) && a < b) {
                ll ways = freq[a] * (ll)(freq[b] * (freq[b] - 1) / 2);
                ans += ways;
            }
        }
    }
    
    // [케이스 3] 세 원소 모두 다른 경우 (a, b, c) with a < b < c
    int m = uni.size();
    for (int i = 0; i < m; i++){
        int st = i + 1, en = m - 1;
        while(st < en){
            int sum = uni[i] + uni[st] + uni[en];
            if(sum == 0){
                ans += (ll)freq[uni[i]] * freq[uni[st]] * freq[uni[en]];
                st++;
                en--;
            } else if(sum < 0){
                st++;
            } else{
                en--;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
