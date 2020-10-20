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
    if (isEmpty(list)) {
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
    if (!isEmpty(list)) {
        Node *pointer = list->head; // Auxiliary pointer to change head value to next node value;
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}

Node *atPosition(List *list, int index) {
    if (index >= 0 && index < list->size) {
        Node *node = list->head; // Taking head value without change reference;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }
    return NULL;
}

int indexOf(List *list, Node *node) {
    if (node != NULL) {
        Node *pointer = list->head;

        int index = 0;
        while (pointer != node && pointer != NULL) {
            pointer = pointer->next;
            index++;
        }
        if (pointer != NULL)
            return index;
    }
    printf("Node not exists at list");
    return -1;
}

void delete(List *list, int index) {
    if (index == 0) {
        pop(list);
    } else {
        Node *current = (Node *) atPosition(list, index);
        if (current != NULL) {
            Node *previousNode = (Node *) atPosition(list, index - 1);
            previousNode->next = current->next;

            free(current);
            list->size--;
        }
    }
}

void insert(List *list, int number, int index) {
    if (index == 0) {
        push(list, number);
    } else {
        Node *current = atPosition(list, index);
        if (current != NULL) {
            Node *previous = atPosition(list, index - 1);
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->data = number;
            previous->next = newNode;
            newNode->next = current;
            list->size++;

        }
    }
}

int main() {
    List *list = createList();
    printf("%d\n", list->size);
    print(list);

    push(list, 55);
    printf("%d \n", list->head->data);

    delete(list, 0);
    print(list);

    insert(list, 200, 2);
    print(list);

    insert(list, 89, 0);
    print(list);
}


