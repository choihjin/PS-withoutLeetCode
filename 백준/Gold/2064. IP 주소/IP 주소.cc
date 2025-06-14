#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;
int n;
ll ips[1002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        
        stringstream ss(tmp);
        while(getline(ss, tmp, '.')) {
            ips[i] = (ips[i] << 8) + stoi(tmp);
        }
    }

    ll min_ip = *min_element(ips, ips+n);
    ll max_ip = *max_element(ips, ips+n);
    ll res_xor = min_ip ^ max_ip;

    int prefix_len = 32;
    for(int i = 31; i >= 0; i--) {
        if((res_xor >> i) & 1) {
            prefix_len = i;
            break;
        }
    }
    int mask_len = 32 - prefix_len;

    ll net_mask = 0;
    if(prefix_len != 32)
        net_mask = (~0LL) << (32 - mask_len + 1); // 32비트 전체를 활용
    else
        net_mask = ~0LL; // 모두 같은 경우

    ll net_addr = min_ip & net_mask;

    string str_net_addr, str_net_mask;
    for(int i = 3; i >= 0; i--) {
        int octet_addr = (net_addr >> (8*i)) & 0xFF;
        int octet_mask = (net_mask >> (8*i)) & 0xFF;
        str_net_addr += to_string(octet_addr);
        str_net_mask += to_string(octet_mask);
        if(i != 0) {
            str_net_addr += ".";
            str_net_mask += ".";
        }
    }
    
    cout << str_net_addr << endl << str_net_mask << endl;

    return 0;
}