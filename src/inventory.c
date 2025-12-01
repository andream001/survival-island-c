#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/inventory.h"

Inventory* inventory_create(int initial_capacity) {
    Inventory *inv = (Inventory *)malloc(sizeof(Inventory));
    if (inv == NULL) return NULL;
    
    inv->items = (InventoryItem *)calloc(initial_capacity, sizeof(InventoryItem));
    if (inv->items == NULL) {
        free(inv);
        return NULL;
    }
    
    inv->count = 0;
    inv->capacity = initial_capacity;
    inv->total_weight = 0.0f;
    
    return inv;
}

void inventory_add_item(Inventory *inv, const char *name, ItemType type, int quantity, float weight, int priority) {
    if (inv == NULL || inv->count >= inv->capacity) return;
    
    InventoryItem *item = &inv->items[inv->count];
    strncpy(item->name, name, 49);
    item->name[49] = '\0';
    item->type = type;
    item->quantity = quantity;
    item->weight = weight;
    item->priority = priority;
    
    inv->total_weight += weight;
    inv->count++;
}

void inventory_display(Inventory *inv) {
    if (inv == NULL || inv->count == 0) {
        printf("Inventario vazio!\\n");
        return;
    }
    
    printf("\\n========== INVENTARIO DO SOBREVIVENTE =========\\n");
    printf("%-20s | %8s | %10s | %8s | %10s\\n", "Nome", "Tipo", "Quantidade", "Peso", "Prioridade");
    printf("%s\\n", "------------------------------------------");
    
    const char *types[] = {"Alimento", "Arma", "Ferramenta"};
    
    for (int i = 0; i < inv->count; i++) {
        InventoryItem *item = &inv->items[i];
        printf("%-20s | %8s | %10d | %8.2f | %10d\\n",
               item->name,
               types[item->type],
               item->quantity,
               item->weight,
               item->priority);
    }
    
    printf("%s\\n", "------------------------------------------");
    printf("Total de itens: %d | Peso total: %.2f kg\\n", inv->count, inv->total_weight);
    printf("==============================================\\n\\n");
}

int inventory_get_item_count(Inventory *inv) {
    return (inv != NULL) ? inv->count : 0;
}

float inventory_get_total_weight(Inventory *inv) {
    return (inv != NULL) ? inv->total_weight : 0.0f;
}

void inventory_free(Inventory *inv) {
    if (inv != NULL) {
        free(inv->items);
        free(inv);
    }
}
