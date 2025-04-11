#include <stdio.h>
#include <assert.h>

/* 
    Scrivere una funzione che data una stringa, determini se le parentesi tonde nella stringa sono bilanciate. 
    In una stringa le parentesi sono bilanciate se il numero di '(' è equivalente a ')' e non si incontra una parentesi ')' prima di aver trovato la corrispondente '('.  
    Ad esempio: 
        parentesi_bilanciate("(())") -> 1;
        parentesi_bilanciate("(a)b()") -> 1;
        parentesi_bilanciate("())(") -> 0;
 */


int parentesi_bilanciate(char *s);
void test_parentesi_bilanciate();
void versione_per_consegna_moodle();


int main(void) {

    //test_parentesi_bilanciate();
    versione_per_consegna_moodle();

}


void test_parentesi_bilanciate() {

    assert(parentesi_bilanciate("(())")==1);
    assert(parentesi_bilanciate("()())")==0);
    assert(parentesi_bilanciate("(a)b()")==1);
    assert(parentesi_bilanciate("())()")==0);
    assert(parentesi_bilanciate("")==1);
    printf("parentesi_bilanciate: tutti i test superati con successo\n");

}


void versione_per_consegna_moodle() {

    char s[50];
    scanf("%s", s);
    printf("parentesi%s bilanciate\n", parentesi_bilanciate(s)?"": " non");

}

int parentesi_bilanciate(char *s) {
    int need_close = 0;
    while (*s != '\0') {
        if (*s == '(') need_close++;
        else if (*s == ')') {
            if (need_close == 0) return 0;
            need_close--;
        }
        s++;
    }

    return need_close == 0;
}