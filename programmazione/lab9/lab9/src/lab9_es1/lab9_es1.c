#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FORMATO FILE STUDENTI:
 * File testuale, una riga per ogni studente nel formato seguente:
 * nome cognome voto1 voto2 voto3 voto4 voto5
 * Il numero di linee del file corrisponde quindi al numero di studenti
 */

// PRE: fp punta all'inizio di un file studenti
int conta_linee(FILE *fp);
// POST: conta il numero di entries nel file, fp punta di nuovo all'inizio del file

void leggi_studente(FILE *fp, Studente *s);
// POST: legge da file i dati relativi ad un unico studente e li copia nella variabile studente puntata da s

int main(void) {
    FILE *fp;
    fp = fopen("studenti.txt", "r");
    if (fp == NULL) {
        printf("Il file non può essere aperto\n");
        return 1;
    }

    int n_stud = conta_linee(fp);
    Studente s[n_stud];

    for (int i = 0; i < n_stud; i++) {
        leggi_studente(fp, s + i);
    }

    fclose(fp);
    printf("Trovati %d studenti\n", n_stud);

    for (int i = 0; i < n_stud; i++) {
        printf("%d) %s %s\n", i + 1, s[i].nome, s[i].cognome);
        // printf("\t");
        // for (int j = 0; j < N_VOTI; j++) printf("%d ", s[i].voti[j]);
        // printf("\n");
    }

    return 0;
}

void leggi_studente(FILE *fp, Studente *s) {
    fscanf(fp, "%s %s %d %d %d %d %d", s->nome, s->cognome, &s->voti[0], &s->voti[1], &s->voti[2], &s->voti[3], &s->voti[4]);
}

int conta_linee(FILE *fp) {
    static char buffer[256 + 256 + 5 * sizeof(int)];
    uint number_of_lines = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        number_of_lines++;
    }
    rewind(fp);
    return number_of_lines;
}
