#include <stdio.h>

int main(){
    int bits[] = {0,1,0,1,0,0,0,1,0,0,1,1,0,1};
    // int bits[] = {0,1,1,1,0,1,0,1,0,0,1,1,0,1};
    int maxCount = 0, maxIndex = 0, currentItem = 0, currentCount = 0, i, maxtype = 0;

    for (i = 0; i < (sizeof(bits)/sizeof(bits[0])); i++){
        printf("%d) %d\n", i, bits[i]);
        if (currentItem != bits[i]){
            // check logic to see if bigger than max
            if (currentCount > maxCount){
                maxCount = currentCount;
                maxIndex = i - currentCount;
                printf("maxIndex = %d - %d\n", i, currentCount);
                maxtype = bits[i];
            }

            // invert and reset the current item
            currentItem = 1 - currentItem;
            currentCount = 0;
        }

        currentCount++;
    }

    // we will perform one more check after the loop
    if (currentCount > maxCount){
        maxCount = currentCount;
        maxIndex = i - currentCount;
    }
    
    printf("max count of %d is %d at index of %d", maxtype, maxCount, maxIndex);
    return 0;
}