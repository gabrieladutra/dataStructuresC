#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 101
int numbers[MAX_SIZE];
int top = -1;

void push(int number) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack overflow \n");
        return;
    }
    numbers[++top] = number;
}

bool isEmpty() {
    return top == -1;
}

void pop() {
    if (isEmpty() == false) {
        printf("Error: There are no elements to pop \n");
    }
    top--;
}

void printStack() {
    for (int i = 0; i <= top; i++) {
        printf(" %d ", numbers[i]);
    }
}

int main() {
    pop();
    push(2);
    push(55);
    push(7);
    push(46535);
    push(0);
    pop();
    printStack();


    return 0;
}

