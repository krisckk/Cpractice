#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,q;
    scanf("%d %d", &a, &q);

    int requests[q];
    int condition[a + 2];

    for (int s = 1; s <= a; s++)
        condition[s] = 1;
    for (int i = 0; i < q; i++)
        scanf("%d", &requests[i]);

    int k = q - 1;
    int same = 0;

    for (int j = 0; j < q; j++)
    {
        if(condition[requests[k]])
            printf("%d\n",requests[k]);
        else
            same++;

        condition[requests[k]]=0;
        k--;
    }

    for (int r = 1; r < a + 1; r++)
        if (condition[r]) printf("%d\n",r);

    return 0;
}
