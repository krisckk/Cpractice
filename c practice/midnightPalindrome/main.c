#include <stdio.h>
#include <string.h>
#define MAX_N 2000
int n;
char s[MAX_N + 1];

int main(){

    int testcase = 0;
    scanf("%d", &testcase);
    while(testcase--){    
        int ans = 0;
        scanf("%s", s);
        n = strlen(s);
        for(int mid = 0; mid < n; mid++){
            //odd
            for(int i = 0; mid + i < n && mid - i >= 0; i++){
                if(s[mid + i] == s[mid - i]) ans++;
                else break;
            }
            //even
            for(int i = 0; mid + 1 + i < n && mid - i >= 0; i++){
                if(s[mid + 1 + i] == s[mid - i]) ans++;
                else break;
            }

        }
        printf("%d\n", ans);
    }

}