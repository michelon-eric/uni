#include <advanced/lista.h>
#include <stdlib.h>
#include <stdio.h>

/* Il seguente esercizio richiede la creazione di una funzione che filtra una lista creandone una nuova 
* con tutti e soli gli elementi, nello stesso ordine,che hanno un campo val maggiore o uguale a un certo 
* valore (la firma della funzione non è fornita).
*/

// filter(...)
/*Data una lista di partenza, restituire una nuova lista con tutti e soli gli elementi maggiori o uguali 
di una certa soglia (nello stesso ordine) */

struct nodo* filter(struct nodo* list, int threshold);

#define node_foreach(__list, __element, __code) for (struct nodo* __element = __list; __element; __element = __element->next) __code

int main(){
	struct nodo* list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        suf_insert(&list, val);
    }
    print_list(list);

    int thres;
    scanf("%d", &thres);
    //filtra qui
    struct nodo* nuova_lista = filter(list, thres);
    print_list(nuova_lista);
}

struct nodo* filter(struct nodo* list, int threshold) {
    struct nodo* new_list = NULL, *start = NULL;
    node_foreach(list, node, {
        if (node->info > threshold) {
            if (!new_list) {
                new_list = new_nodo(node->info);
                start = new_list;
            } else {
                new_list->next = new_nodo(node->info);
                new_list = new_list->next;
            }
        }
    });
    return start;
}
