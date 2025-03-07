#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

struct Jewel {
    int value, weight;
};

bool cmp(Jewel a, Jewel b) {
    return a.value > b.value;
}

int N, K;
Jewel jewel[300002]; 
multiset<int> bag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> jewel[i].weight >> jewel[i].value;
    sort(jewel, jewel+N, cmp);
    for(int i=0; i<K; i++) {
        int tmp;
        cin >> tmp;
        bag.insert(tmp);
    }

    ll ans = 0;
    for(int i=0; i<N; i++) {
        if(!bag.size()) break;
        int w = jewel[i].weight;
        int v = jewel[i].value;
        
        auto iter = bag.lower_bound(w);
        if(iter != bag.end()) {
            ans += v;
            bag.erase(iter);
        }
    }

    cout << ans << endl;

    return 0;
}