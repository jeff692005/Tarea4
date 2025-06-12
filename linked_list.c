#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* head = NULL;
static unsigned int size = 0;

void linked_list_init() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    size = 0;
}

int linked_list_append(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    size++;
    return 0;
}

int linked_list_prepend(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    size++;
    return 0;
}

int linked_list_remove(int data) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            size--;
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1; // No encontrado
}

int linked_list_contains(int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) return 1;
        current = current->next;
    }
    return 0;
}

unsigned int linked_list_size() {
    return size;
}

void linked_list_print() {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
