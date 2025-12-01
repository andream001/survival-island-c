#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/search.h"

int linear_search(InventoryItem *items, int count, const char *target) {
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, target) == 0) {
            return i;
        }
    }
    return -1;
}

int binary_search(InventoryItem *items, int count, const char *target) {
    int left = 0, right = count - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(items[mid].name, target);
        
        if (cmp == 0) return mid;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void selection_sort(InventoryItem *items, int count, int sort_by) {
    for (int i = 0; i < count - 1; i++) {
        int min_idx = i;
        
        for (int j = i + 1; j < count; j++) {
            int should_swap = 0;
            
            if (sort_by == 0) { // sort by name
                should_swap = strcmp(items[j].name, items[min_idx].name) < 0;
            } else if (sort_by == 1) { // sort by priority (descending)
                should_swap = items[j].priority > items[min_idx].priority;
            } else if (sort_by == 2) { // sort by weight
                should_swap = items[j].weight < items[min_idx].weight;
            }
            
            if (should_swap) min_idx = j;
        }
        
        InventoryItem temp = items[i];
        items[i] = items[min_idx];
        items[min_idx] = temp;
    }
}

void bubble_sort(InventoryItem *items, int count, int sort_by) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int should_swap = 0;
            
            if (sort_by == 0) { // sort by name
                should_swap = strcmp(items[j].name, items[j + 1].name) > 0;
            } else if (sort_by == 1) { // sort by priority (descending)
                should_swap = items[j].priority < items[j + 1].priority;
            } else if (sort_by == 2) { // sort by weight
                should_swap = items[j].weight > items[j + 1].weight;
            }
            
            if (should_swap) {
                InventoryItem temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void print_search_times(InventoryItem *items, int count) {
    printf("\\n========== BENCHMARK DE BUSCA ==========\\n");
    printf("Total de itens: %d\\n\\n", count);
    
    const char *search_target = items[count / 2].name;
    
    clock_t start = clock();
    linear_search(items, count, search_target);
    clock_t end = clock();
    double linear_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    
    start = clock();
    binary_search(items, count, search_target);
    end = clock();
    double binary_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    
    printf("Busca Linear: %.6f ms\\n", linear_time);
    printf("Busca Binaria: %.6f ms\\n", binary_time);
    printf("Alvo: %s\\n", search_target);
    printf("========================================\\n\\n");
}
