#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "inventory.h"

typedef struct Node {
    InventoryItem data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

// Function declarations
LinkedList* ll_create(void);
void ll_insert(LinkedList *list, InventoryItem item);
Node* ll_search(LinkedList *list, const char *name);
void ll_display(LinkedList *list);
void ll_free(LinkedList *list);
int ll_get_size(LinkedList *list);

#endif // LINKED_LIST_H
