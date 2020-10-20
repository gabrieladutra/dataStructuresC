#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
struct Node *head;


void insertAtBeginning(int number) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = number;
    temp->next = head;
    head = temp;

}

void printList() {
    Node *temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    head = NULL;
    printf("How many numbers? \n");
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n Enter the number \n");
        scanf("%d", &x);
        insertAtBeginning(x);
        printList();
    }
    return 0;
}


