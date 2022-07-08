#include <stdio.h>

int sum_digits(int number){
    int sum = 0;
    
    while(number != 0){
        printf("number = %d\n", number);
        sum += number % 10;
        number /= 10;
    }
    
    return sum;
}

int main(){
    int x = 537;
    printf("%d", sum_digits(x));
    return 0;
}