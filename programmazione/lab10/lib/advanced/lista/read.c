#include "../lista.h"

int isempty(struct nodo* ptr){
    return ptr==NULL? 1: 0;
}

void print_list(struct nodo* ptr){
    if(isempty(ptr)==1){
        printf("Vuota\n");
    }
    else{
        while(isempty(ptr)==0){
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
