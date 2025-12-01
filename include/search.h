#ifndef SEARCH_H
#define SEARCH_H

#include "inventory.h"
#include <time.h>

// Search algorithms
int linear_search(InventoryItem *items, int count, const char *target);
int binary_search(InventoryItem *items, int count, const char *target);

// Sort algorithms
void selection_sort(InventoryItem *items, int count, int sort_by);
void bubble_sort(InventoryItem *items, int count, int sort_by);

// Sort criteria: 0=name, 1=priority, 2=weight

// Utility
void print_search_times(InventoryItem *items, int count);

#endif // SEARCH_H
