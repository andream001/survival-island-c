#include <stdio.h>
#include "../include/inventory.h"
int main(void) {
    printf("FASE 1 - Teste\n");
    Inventory *inv = inventory_create(10);
    if(inv) inventory_free(inv);
    return 0;
}
