#include <stdio.h>
#include "../include/linked_list.h"
int main(void) {
    printf("FASE 2 - Teste\n");
    LinkedList *list = ll_create();
    if(list) ll_free(list);
    return 0;
}
