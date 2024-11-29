#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

typedef long long ll;

typedef struct _Mat{
    ll data[3][3];
} Mat;
Mat I;

Mat matmul(Mat x, Mat y){
    Mat res;
    memset(res.data, 0, sizeof(res.data));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                res.data[i][j] += (x.data[i][k] * y.data[k][l]) % MOD;
                res.data[i][j] %= MOD;
            }
        }
    }
    return res;
}

Mat fpw(Mat x, ll y){
    if(y == 0) return I;
    Mat result = I;
    if(y % 2 == 1) result = matmul(result, x);
    Mat tmp = fpw(x, y / 2);
    return matmul(result, matmul(tmp, tmp));
}

int main(){
    
}