#include <cstdio>

int main() {
    int ans = 0, sum = 0;
    for (int i=0; i<4; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        sum += (y-x);
        if (ans < sum) ans = sum;
    }
    printf("%d\n", ans);
    return 0;
}