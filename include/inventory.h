#ifndef INVENTORY_H
#define INVENTORY_H

#include <time.h>

typedef enum {
    FOOD = 0,
    WEAPON = 1,
    TOOL = 2
} ItemType;

typedef struct {
    char name[50];
    ItemType type;
    int quantity;
    float weight;
    int priority; // 1-10, higher is more important
} InventoryItem;

typedef struct {
    InventoryItem *items;
    int count;
    int capacity;
    float total_weight;
} Inventory;

// Function declarations
Inventory* inventory_create(int initial_capacity);
void inventory_add_item(Inventory *inv, const char *name, ItemType type, int quantity, float weight, int priority);
void inventory_display(Inventory *inv);
void inventory_free(Inventory *inv);
int inventory_get_item_count(Inventory *inv);
float inventory_get_total_weight(Inventory *inv);

#endif // INVENTORY_H
