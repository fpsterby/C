#include <stdio.h>

void print_int(int x){
    switch (x) {
            case 0:
                printf("zero");
                break;
            case 1:
                printf("one");
                break;
            case 2:
                printf("two");
                break;
            case 3:
                printf("three");
                break;
            case 4:
                printf("four");
                break;
            case 5:
                printf("five");
                break;
            case 6:
                printf("six");
                break;
            case 7:
                printf("seven");
                break;
            case 8:
                printf("eight");
                break;
            case 9:
                printf("nine");
                break;
            case 10:
                printf("ten");
                break;
        }
}

int num_to_word(int num){
    int x = num;
    int newnum = 0;
    
    while (x != 0){
        newnum *= 10;
        newnum += x % 10;

        x /= 10;
    }

    while (newnum != 0){
        print_int(newnum % 10);
        printf(" ");
        newnum /= 10;
    }
}

int main(){
    int x = 503;
    num_to_word(x);
    return 0;
}