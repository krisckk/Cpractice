#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    long long treasure[n + 1];
    long long answer[q];
    int l, r, m;

    //start from 1
    for (int i = 1; i <= n; i++)
        scanf("%lld", &treasure[i]);

    //prefix
    long long prefix[n + 1];
    prefix[1] = 0;
    for (int p = 1; p <= n; p++)
    {
        if (treasure[p] > 0) prefix[p] = prefix[p - 1] + treasure[p];
        else prefix[p] = prefix[p - 1];
    }


    for (int j = 0; j < q; j++)
    {
        scanf("%d %d %d",&l,&r,&m);
        answer[j]=0;

        if(m == 0) answer[j]=0;
        else answer[j]=prefix[l+m-1]-prefix[l-1];

    }


    for (int z=0;z<q;z++) printf("%lld\n",answer[z]);

    return 0;
}
