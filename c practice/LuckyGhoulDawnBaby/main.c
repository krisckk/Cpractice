#include <stdio.h>
#include <stdlib.h>

int main(){
    int arraySize, queries;
    while(scanf("%d %d", &arraySize, &queries) != EOF){
        int array[arraySize];
        for(int i = 0; i < arraySize; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < queries; i++){
            int number;
            scanf("%d", &number);
            int count = 0;
            for(int j = 0; j < arraySize; j++){
                if(array[j] != number){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count == arraySize){
                printf("Break your bridge!\n");
            }
            else{
                printf("%d\n", count + 1);
            }
        }
    }
    return 0;
}