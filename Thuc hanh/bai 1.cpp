#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node *next;
} *head;


Node* insertNode(Node *node, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (node == NULL) {
        node = newNode;
        return node;
    }
    Node* current = node;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return node;
}

Node* insert(int n, int data) {
    if (n == 0) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *current = head->next;
    Node *prev = head;
    while (current->next != NULL && --n > 0) {
        prev = current;
        current = prev->next;
    }
    if (n == 0) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = current;
        prev->next = newNode;
    }
    return head;
}

Node* insert(int data) {
    head = insertNode(head, data);
    return head;
}


Node* sortedInsert(int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL) {
        newNode->next = NULL;
        return newNode;
    }
    if(head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        while(current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

Node* remove(int data) {
    if (head->data == data) {
        head = head->next;
        return head;
    }
    Node *current = head;
    while (current->next->data != data) {
        current = current->next;
    }
    if (current->next->data == data) {
        current->next = current->next->next;
    }
    return head;

}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
}

int main() {
    int x;
    do {
        printf("nhap x: ");
        scanf("%d", &x);
        if (x >= 0) head = sortedInsert( x);
    } while (x >= 0);

    remove(6);
    printList(head);
}