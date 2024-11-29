#include <stdio.h>

int main(){
    int strlength;
    scanf("%d", &strlength);
    int str[strlength];
    int queries[strlength];
    int condition[strlength + 1];
    int output[strlength];
    for(int i = 0; i < strlength; i++){
        scanf("%d", &str[i]);
    }
    for(int i = 0; i < strlength; i++){
        scanf("%d", &queries[i]);
    }
    for(int i = 1; i <= strlength; i++){
        condition[i] = 1;
    }
    for(int i = 0; i < strlength; i++){
        int count = 0;
        for(int j = 0; j < strlength; j++){
            if(queries[i] != str[j]){
                if(condition[str[j]] == 1){
                    condition[str[j]] = 0;
                    count++;
                }
            }
            else{
                if(condition[str[j]] == 1){
                    condition[str[j]] = 0;
                    count++;
                }
                break;
            }
        }
        output[i] = count;
    }
    for(int i = 0; i < strlength; i++){
        printf("%d ", output[i]);
    }
}