#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX_N = 50000;

ll count_xy[MAX_N*2+2]; // 用到最大是 B+C+1，所以開 MAX_N*2+2

void solve() {
    int A, B, C, D;
    ll ans = 0;
    scanf("%d%d%d%d", &A, &B, &C, &D);

    // 計算 x+y 的組合數，其中 count_xy[i] 表示 x+y=i 的組合數
    for(int x = A; x <= B; ++x) {
        // 在 x+B 處標記+1, x+C+1 處標記 -1，做一遍前綴和就能讓 x+B ~ x+C 的地方都 +1，且不影響到其他地方的數值
        // 對每一組 (x+B, x+C+1) 都這樣標記的話，全部標完之後就只要做一次前綴和就可以了
        ++count_xy[x+B];
        --count_xy[x+C+1];
    }
    for(int i = A + B; i <= B + C + 1; ++i)
        count_xy[i] += count_xy[i - 1];

    // 對於 x+y=i 的狀況而言，能組出三角形的符合條件的第三邊一定是 z < x+y = i (z<i)，可以看做是 z <= i-1 (因為都是整數)
    // 再加上原本的條件: C <= z <= D，綜合起來就是 C <= z <= min(D, i-1)
    for(int i = A + B; i <= B + C; ++i) {
        int num_of_z = max(min(D, i - 1) - C + 1, 0);
        ans += count_xy[i] * num_of_z;
    }
    printf("%lld\n", ans);

    // reset
    memset(count_xy, 0, sizeof(ll) * (B + C + 2));
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
}