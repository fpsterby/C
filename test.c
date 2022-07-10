#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next; 
} node_t;

void print_list(node_t *head){
    node_t *current = head;
    while(current-> next != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void swap_values(node_t *a, node_t *b){
    int hold = a->value;
    a->value = b->value;
    b->value = hold;
}

void sort(node_t *head){
    unsigned int running = 1; // this is to control the condition of the sorting loop
    unsigned int changed = 0; // this is used later to decide completion or not

    node_t *node = head; // set the current node to the head ie index of 0
    while (running == 1){
        node_t *nextNode = node->next; 
        if(node->value > nextNode->value){
            swap_values(node, nextNode);
            changed = 1;
        }

        node = node->next;
        
        if (node->next == NULL){ // this checks if last index of linked list
            
            if (changed){ // if the list has been changed
                node = head; // loop again
                changed = 0; // rest the changed condition
            } else {
                running = 0; // if nothing has been changed, then sorted.
            }
        }
    }
}

int enter_num(){
    int x;

    printf("please enter an input: ");
    scanf("%d", &x);
    return x;
}

int main(){
    int x = enter_num();
    node_t *head = check_prime(x);
    
    print_list(head);
    
    sort(head);

    printf("sorted list:\n");
    print_list(head);
    
    return 0;
}