#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _product
{
    int day1, day2;
} Product;
int min(int a, int b) {
    return (a < b) ? a : b;
}
int cmp(const void *L, const void *R){
    Product l = *(Product*)L, r = *(Product*)R;
    int diffL = l.day1 - l.day2;
    int diffR = r.day1 - r.day2;
    return diffL - diffR;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    Product *p = (Product*)malloc(sizeof(Product) * n);
    for(int i  = 0; i < n; i++){
        scanf("%d", &p[i].day1);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i].day2);
    }
    qsort(p, n, sizeof(p[0]), cmp);
    int answer = 0;
    for(int i = 0; i < k; i++){
        answer += p[i].day1;
    }
    for(int i = k; i < n; i++){
        answer += min(p[i].day1, p[i].day2);
    }
    printf("%d\n", answer);
    free(p);
}
