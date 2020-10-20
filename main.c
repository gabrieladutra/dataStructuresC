#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct List {
    int size;
    Node *head;
} List;

List *createList() {
    List *list = (List *) malloc(sizeof(List)); //Referencing a variable to point to List
    list->size = 0; // Initializing  a list size
    list->head = NULL; // When list is empty
}

void push(List *list, int number) {
    Node *node = (Node *) malloc(sizeof(Node)); //Referencing a variable to point to Node
    node->data = number; // Assigning value to node
    node->next = list->head; // Making node point to List(head), in this case point to null
    list->head = node;// Head now point to node;
    list->size++; // Incrementing list size
}

bool isEmpty(List *list) {
    return list->size == 0;
}
void print(List *list) {
    if(isEmpty(list)){
        printf("List is Empty.\n");
        return;
    }

    Node *pointer = list->head;// Taking head value without change reference;
    printf("List: ");
    while (pointer != NULL) {
        printf(" %d ", pointer->data);
        pointer = pointer->next; // Taking next value to print
    }
    printf("\n");
}

void pop(List *list) {
    if(!isEmpty(list)){
        Node* pointer = list->head; // Auxiliary pointer to change head value to next node value;
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}

int main() {
    List *list = createList();
    printf("%d\n", list->size);
    print(list);

    push(list, 55);
    printf("%d \n", list->head->data);

    push(list, 234);
    push(list, 111);
    print(list);
    pop(list);
    print(list);


}


