#ifndef ESCAPE_TOWER_H
#define ESCAPE_TOWER_H

#include "inventory.h"

#define TOWER_LEVELS 5

typedef struct {
    char component[50];
    int required_quantity;
    ItemType component_type;
    int collected;
} TowerComponent;

typedef struct {
    int level_number;
    TowerComponent *components;
    int component_count;
    int is_complete;
} TowerLevel;

typedef struct {
    TowerLevel *levels;
    int total_levels;
    int completed_levels;
} EscapeTower;

// Function declarations
EscapeTower* tower_create(void);
void tower_add_level(EscapeTower *tower, int level);
void tower_add_component(EscapeTower *tower, int level, const char *component, int quantity, ItemType type);
int tower_build_level(EscapeTower *tower, int level, Inventory *inv);
int tower_is_complete(EscapeTower *tower);
void tower_display_progress(EscapeTower *tower);
void tower_free(EscapeTower *tower);

#endif // ESCAPE_TOWER_H
