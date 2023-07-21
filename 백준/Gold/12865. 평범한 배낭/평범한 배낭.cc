#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int value;
    int weight;
    double value_per_weight;
} Item;

Item items[102];
int n, W;

int main() {
    cin >> n >> W;

    for(int i=0; i<n; i++) 
        cin >> items[i].weight >> items[i].value;
    
    vector<vector<int> > B(n+1, vector<int>(W+1));
    for(int w=0; w<=W; w++) 
        B[0][w] = 0;
    for(int i=1; i<=n; i++) {
        B[i][0] = 0;
        for(int w=1; w<=W; w++) {
            if(items[i-1].weight <= w) 
                B[i][w] = max(items[i-1].value + B[i-1][w-items[i-1].weight], B[i-1][w]);
            else
                B[i][w] = B[i-1][w];
        }
    }
    
    cout << B[n][W] << "\n";

    return 0;
}