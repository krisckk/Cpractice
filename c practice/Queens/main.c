#include <stdio.h>
#include <string.h>
int n;
int v[15];
int dl[30];
int dr[30];

int getans(int row){
    if(row == n){
        return 1;
    }
    int res = 0;
    for(int col = 0; col < n; col++){
        if(v[col] || dl[row + col] || dr[row - col + 15]) continue;
        //place queen on (row, col)
        v[col] = 1;
        dl[row + col] = 1;
        dr[row - col + 15] = 1;
        res += getans(row + 1);
        //remove queen on (row, col)
        v[col] = 0;
        dl[row + col] = 0;
        dr[row - col + 15] = 0;
    }
    return res;
}
int main(){
    scanf("%d", &n);
    int result = getans(0);
    printf("%d\n", result);
    return 0;

}
