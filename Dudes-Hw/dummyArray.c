#include <stdio.h>

int main(){
    int array[] = {9,4,3,5,6,7,8,1,11};
    int arraySize = (sizeof(array) /  sizeof(array[0]));
    int sortedArray[arraySize];
    int midPoint = arraySize / 2, i = 0;

    while(i < arraySize){ // use a for loop because it's always iterating through i++ but im lazy
        int incrementer = i / 2;
        if (i % 2 == 1){
            incrementer++;
            incrementer *= -1;
        }

        int targetIndex = midPoint + incrementer;
        sortedArray[i] = array[targetIndex];
        i++;
    }

    //print final array
    for (int n = 0; n < arraySize; n++){
        printf("%d ", sortedArray[n]);
    }

}