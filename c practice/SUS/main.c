#include <stdio.h>

int pre[9], post[9];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int ans = 1;
        for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
        for(int i = 0; i < n; ++i) scanf("%d", &post[i]);
        for(int i = 0; i < n - 1; ++i) {
            for(int j = 0; j < n - 1; ++j) {
            	if((pre[i] == post[j+1]) && (pre[i+1] == post[j])) {
                    ans *= 2;
                }
        	}
        }
        printf("%d\n", ans);
    }
    return 0;
}
