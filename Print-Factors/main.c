#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next; 
} node_t;

void print_list(node_t *head){
    node_t *current = head;
    while(current != NULL) {
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
    int counter = 0;

    node_t *node = head; // set the current node to the head ie index of 0
    
    while (running == 1){
        
        node_t *nextNode = node->next; 
        if(node->value > nextNode->value){
            if(nextNode!= NULL){
                swap_values(node, nextNode);
                print_list(head);
                changed = 1;
            }
        }

        node = node->next;

        if (node->next == NULL){ // this checks if last index of linked list
        print_list(head);
            printf("new loop\n");
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

node_t* check_prime(int number){
    int upper = number / 2 + 1; // works out the upper bound

    node_t * head = NULL; // initialize the linked list node
    head = (node_t *) malloc(sizeof(node_t)); // allocate memory to new node
    node_t* node = head; // assigns a variable to store the head of the node
    node_t *prevNode; // used to make sure the last node isn't pointing to an 
    for (int i = 1; i < upper; i++){ // need to find a way to make this work
        if (number % i == 0){
            upper = number / i; // could add logic

            node->value = i;
            node->next = (node_t *) malloc(sizeof(node_t));
            node = node->next;

            node->value = number / i;
            if (i < upper - 5) {
                node->next = (node_t *) malloc(sizeof(node_t));
                node = node->next;
            }
        }
    }
    // there is a fucked up thing, where the final node will point to an empty node
    return head;
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