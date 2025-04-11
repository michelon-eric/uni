#include <stdio.h>
#include <assert.h>

/*
	Funzione che determina se almeno una faccia di un array tridimensionale di interi è composta da tutti elementi uguali. 
*/


int controlla_facce(int *m, int dim);
void test_controlla_facce();
void consegna_moodle ();
void leggi_array(int *m, int dim);
void stampa_cubo(int *m, int dim);


int main () {

	//test_controlla_facce();
	consegna_moodle();
}


void test_controlla_facce() {

	int X[2][2][2] = {{{0,0},{0,0}},{{1,2},{3,4}}};
	//stampa_cubo(&X[0][0][0],2);
	assert(controlla_facce(&X[0][0][0], 2)==1);
	int X2[2][2][2] = {{{0,3},{1,1}},{{4,2},{1,1}}};
	assert(controlla_facce(&X2[0][0][0], 2)==1);
	int X3[2][2][2] = {{{0,3},{1,1}},{{4,2},{1,6}}};
	assert(controlla_facce(&X3[0][0][0], 2)==0);
	printf("Tutti i test passati con successo!\n");
}


void consegna_moodle () {

	int dim;
	scanf("%d", &dim);
	int cub[dim][dim][dim];
	leggi_array(&cub[0][0][0], dim*dim*dim);
	
	if (controlla_facce(&cub[0][0][0], dim))
		printf("Almeno una faccia con valori identici\n");
	else
		printf("Nessuna faccia con valori identici\n");
	//stampa_cubo(&cub[0][0][0], dim);

}


void leggi_array(int *m, int dim) {

	for(int i=0; i<dim*dim*dim; i+=1)
		scanf("%d", m+i);
}


void stampa_cubo(int *cub, int dim) {

	for (int i=1;i<=dim*dim*dim;i+=1) {
		printf("%d ", *(cub+i-1));
		if (i%dim==0)
			printf("\n");
		else if (i%dim*dim==0)
				printf("\n");
	}
}
