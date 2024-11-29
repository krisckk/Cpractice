#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define MAX_N 1000000
char str[10000000];

int main()
{
    int t;
    int x;
    scanf("%d",&t);
    long long output[11];

    for (int T = 0; T < t; T++)
    {
        scanf("%d", &x);
        scanf("%s", str);
        long long length = strlen(str);
        long long ans = length;
        long long copy_len;
        int copy_time;

        for (int i = 0; i < x; i++)
        {
            if (length >= x)
            {
                
                copy_time = str[i] - '1';
                copy_len = ans - i - 1;
                if (copy_len < 0) copy_len += MOD; //important
                
                ans += (copy_len * copy_time) % MOD;
                ans = ans % MOD;
                
                
            }
            else 
            {
                copy_time = str[i] - '1';
                copy_len = length - i - 1;
                while(copy_time--)
                {
                    strncpy(str+length,str+i+1,copy_len); 
                    str[length+copy_len] = '\0'; 
                    length += copy_len;
                    ans += copy_len;
                }
                
            }
            
        }
        output[T] = ans;
    }
    
    
    
    //printf("%s\n",str);
    for (int r = 0; r < t; r++)
        printf("%lld\n", output[r]);
    return 0;
}