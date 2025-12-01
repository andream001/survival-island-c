#include <stdio.h>
#include "../include/escape_tower.h"
int main(void) {
    printf("FASE 3 - Teste\n");
    EscapeTower *tower = tower_create();
    if(tower) tower_free(tower);
    return 0;
}
