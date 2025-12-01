#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/escape_tower.h"

EscapeTower* tower_create(void) {
    EscapeTower *tower = (EscapeTower *)malloc(sizeof(EscapeTower));
    if (tower == NULL) return NULL;
    
    tower->levels = (TowerLevel *)calloc(TOWER_LEVELS, sizeof(TowerLevel));
    if (tower->levels == NULL) {
        free(tower);
        return NULL;
    }
    
    tower->total_levels = TOWER_LEVELS;
    tower->completed_levels = 0;
    
    for (int i = 0; i < TOWER_LEVELS; i++) {
        tower->levels[i].level_number = i + 1;
        tower->levels[i].components = NULL;
        tower->levels[i].component_count = 0;
        tower->levels[i].is_complete = 0;
    }
    
    return tower;
}

void tower_add_component(EscapeTower *tower, int level, const char *component, int quantity, ItemType type) {
    if (tower == NULL || level < 1 || level > TOWER_LEVELS) return;
    
    int idx = level - 1;
    TowerLevel *lv = &tower->levels[idx];
    
    lv->components = (TowerComponent *)realloc(lv->components, (lv->component_count + 1) * sizeof(TowerComponent));
    if (lv->components == NULL) return;
    
    TowerComponent *comp = &lv->components[lv->component_count];
    strncpy(comp->component, component, 49);
    comp->component[49] = '\0';
    comp->required_quantity = quantity;
    comp->component_type = type;
    comp->collected = 0;
    
    lv->component_count++;
}

int tower_build_level(EscapeTower *tower, int level, Inventory *inv) {
    if (tower == NULL || inv == NULL || level < 1 || level > TOWER_LEVELS) return 0;
    
    int idx = level - 1;
    TowerLevel *lv = &tower->levels[idx];
    
    for (int i = 0; i < lv->component_count; i++) {
        int found_quantity = 0;
        for (int j = 0; j < inv->count; j++) {
            if (strcmp(inv->items[j].name, lv->components[i].component) == 0) {
                found_quantity = inv->items[j].quantity;
                break;
            }
        }
        
        if (found_quantity < lv->components[i].required_quantity) {
            return 0;
        }
        lv->components[i].collected = found_quantity;
    }
    
    lv->is_complete = 1;
    tower->completed_levels++;
    return 1;
}

int tower_is_complete(EscapeTower *tower) {
    if (tower == NULL) return 0;
    return tower->completed_levels == tower->total_levels;
}

void tower_display_progress(EscapeTower *tower) {
    if (tower == NULL) return;
    
    printf("\n===== PROGRESSO DA TORRE DE FUGA =====\n");
    printf("Niveis completos: %d/%d\n\n", tower->completed_levels, tower->total_levels);
    
    for (int i = 0; i < tower->total_levels; i++) {
        TowerLevel *lv = &tower->levels[i];
        printf("NIVEL %d - %s\n", lv->level_number, lv->is_complete ? "[COMPLETO]" : "[INCOMPLETO]");
        
        for (int j = 0; j < lv->component_count; j++) {
            printf("  * %s: %d/%d\\n",
                   lv->components[j].component,
                   lv->components[j].collected,
                   lv->components[j].required_quantity);
        }
    }
    
    printf("======================================\n\n");
}

void tower_free(EscapeTower *tower) {
    if (tower == NULL) return;
    
    for (int i = 0; i < tower->total_levels; i++) {
        free(tower->levels[i].components);
    }
    free(tower->levels);
    free(tower);
}
