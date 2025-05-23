#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int info;
    struct nodo *next;
};

struct nodo* new_nodo(int val);
// POST: return di un puntatore ad un nuovo nodo (allocato dentro la funzione) con campo info == val

/* Fatte in classe */
// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
int isempty(struct nodo* ptr);
// POST: return 1 se la lista è vuota, 0 altrimenti

// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
void print_list(struct nodo* ptr);
// POST: stampa il contenuto della lista (i campi info), "Vuota" se non ci sono elementi

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void pre_insert(struct nodo** pptr, int val);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in testa" (inizio lista) avente campo info == val

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void suf_insert(struct nodo** pptr, int val);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in coda" (fine lista) avente campo info == val

/* Nuove funzioni */
// PRE:  ptr è un puntatore ad una lista (possibilmente vuota)
int lung(struct nodo* ptr);
// POST: return il numero di nodi
// NOTA: è un one-liner se usate la ricorsione

// PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
int get(struct nodo* ptr, int pos);
// POST: return del campo info del nodo pos-esimo

// PRE: ptr è un puntatore ad una lista (possibilmente vuota) passata per riferimento, pos è una posizione valida (tra 0 e lung(ptr)-1)
void modifica(struct nodo** ptr, int pos, int val);
// POST: la lista puntata da ptr è uguale a quella originale ma il nodo in posizione pos ha campo info == val

#define node_foreach(__list, __element, __code) for (struct nodo* __element = __list; __element; __element = __element->next) __code

int main(){
    struct nodo *list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        if(i%2==0){
            pre_insert(&list, val);
        }
        else suf_insert(&list, val);
    }
    print_list(list);

    //raddoppio ogni elemento della lista (codice qui)
    
    node_foreach(list, el, {
        el->info *= 2;
    });
    print_list(list);

    // printf("len=%d\n", lung(list));
    // printf("get(2)=%d\n", get(list, 2));
    // modifica(&list, 2, 0);
    // print_list(list);
}

struct nodo* new_nodo(int val) {
    struct nodo* node = (struct node*)malloc(sizeof(struct nodo));
    node->info = val;
    return node;
}

int isempty(struct nodo* ptr) {
    return !ptr;   
}

void print_list(struct nodo* ptr) {
    struct nodo* temp = ptr;
    while (temp) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

void pre_insert(struct nodo** pptr, int val) {
    struct nodo* new_node = new_nodo(val);
    new_node->next = *pptr;
    *pptr = new_node;
}

void list_go_to_end(struct nodo** pptr) {
    if (isempty(*pptr)) return;
    while((*pptr)->next) *pptr = (*pptr)->next;
}

void suf_insert(struct nodo** pptr, int val) {
    struct nodo* copy = *pptr;
    list_go_to_end(&copy);
    copy->next = new_nodo(val);
}

int lung(struct nodo* ptr) {
    return ptr ? 1 + lung(ptr->next) : 0;
}

struct nodo* get_ref(struct nodo* ptr, int pos) {
    struct nodo* copy = ptr;
    for (int i = 0; i < pos; i++) {
        copy = copy->next;
    }
    return copy;
}

int get(struct nodo* ptr, int pos) {
    return get_ref(ptr, pos)->info;
}

void modifica(struct nodo** ptr, int pos, int val) {
    get_ref(*ptr, pos)->info = val;
}