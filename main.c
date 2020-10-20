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
void insertAtPosition (int data, int position) {
    struct Node* tempNode = malloc(sizeof(struct Node));

    tempNode->data = data;
    tempNode->next = NULL;

    if (position == 1) {
        tempNode->next = head;
        head = tempNode;
        return;
    }

    struct Node* previousNode = head;
    for (int i = 0; i < position - 2; i++) {
        previousNode = previousNode->next;
    }

    tempNode->next = previousNode->next;
    previousNode->next = tempNode;
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

    insertAtPosition(123,4);
    printList();

    return 0;
}


