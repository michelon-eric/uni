#include "../lista.h"

struct nodo* new_nodo(int info){
    struct nodo *temp =  (struct nodo*)malloc(sizeof(struct nodo));
    temp->info = info;
    temp->next = NULL;
    return temp;
}

void pre_insert(struct nodo** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    nuovo->next = *pptr;
    *pptr = nuovo;
}

void suf_insert(struct nodo** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    while(isempty(*pptr)==0){
        pptr = &((*pptr)->next);
    }
    *pptr = nuovo;
}

void delete_list(struct nodo* ptr){
    if (ptr == NULL) return;
    delete_list(ptr->next);
    free(ptr);
}