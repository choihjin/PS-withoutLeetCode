#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int a[10];
    while(1) {
        for(int i=0; i<3; i++) 
            cin >> a[i];
        
        if(a[0] == 0 && a[1] == 0 && a[2] == 0) break;
        
        sort(a, a+3);
        
        if(a[2]*a[2] == a[1]*a[1]+a[0]*a[0]) cout << "right" << endl;
        else cout << "wrong" << endl;
        
    }
    return 0;
}