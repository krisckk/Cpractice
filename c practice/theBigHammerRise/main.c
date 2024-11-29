#include <stdio.h>

int main(){
    int aint, afraction, bint, bfraction;
    scanf("%d.%d %d.%d", &aint, &afraction, &bint, &bfraction);
    int newa = aint * 100 + afraction;
    int newb = bint * 100 + bfraction;
    int result = newa * newb;
    printf("%d.%04d\n", result/10000, result%10000);
    return 0;
}