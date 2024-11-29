#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int ai[n + 1];
    int toeat;
    int pos = 0, count = 0;
    int condition[n + 10];
    int output[n + 1];

    for (int i = 1; i < n + 1; i++)
    {
        condition[i] = 1;
    }

    for (int j = 0;j < n; j++) scanf("%d", &ai[j]);

    for (int k = 0; k < n; k++)
    {
        count = 0;
        scanf("%d", &toeat);

        if (condition[toeat] == 0)
        {
            output[k]=0;
        }
        else
        {
            while (ai[pos] != toeat)
            {
                count++;
                condition[ai[pos]]=0;
                pos++;
            }

            output[k]=count;
        }


    }

    printf("%d ",output[0]+1);
    for (int r = 1; r < n - 1; r++) printf("%d ", output[r]);
    printf("%d\n",output[n-1]);

    return 0;
}