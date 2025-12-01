#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/linked_list.h"

LinkedList* ll_create(void) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

void ll_insert(LinkedList *list, InventoryItem item) {
    if (list == NULL) return;
    
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) return;
    
    new_node->data = item;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

Node* ll_search(LinkedList *list, const char *name) {
    if (list == NULL) return NULL;
    
    Node *current = list->head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void ll_display(LinkedList *list) {
    if (list == NULL || list->head == NULL) {
        printf("Lista encadeada vazia!\\n");
        return;
    }
    
    printf("\\n===== LISTA ENCADEADA DE INVENTARIO =====\\n");
    Node *current = list->head;
    int index = 1;
    const char *types[] = {"Alimento", "Arma", "Ferramenta"};
    
    while (current != NULL) {
        printf("%d. %s (Tipo: %s, Qtd: %d, Prioridade: %d)\\n",
               index++,
               current->data.name,
               types[current->data.type],
               current->data.quantity,
               current->data.priority);
        current = current->next;
    }
    printf("Total de itens: %d\\n", list->size);
    printf("========================================\\n\\n");
}

int ll_get_size(LinkedList *list) {
    return (list != NULL) ? list->size : 0;
}

void ll_free(LinkedList *list) {
    if (list == NULL) return;
    
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
