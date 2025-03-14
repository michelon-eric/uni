
#include <stdio.h>
#include <stdbool.h>

int lab2ex1(void) {
    int threshold = 0;
    scanf("%d", &threshold);
    
    do {
        threshold++;
    } while ((threshold % 2 == 0) || (threshold % 3 == 0) || (threshold % 5 == 0));

    return threshold;
}

void lab2ex2(void) {
    int n1 = 1, n2 = 10;

    for (int i = n1; i <= n2; i++) {
        for (int j = 1; j < 11; j++) {
            printf("%d", i * j);
            if (j != 10) printf(" ");
        }
        printf("\n");
    }
}

void lab2ex3(void) {
    int n;
    scanf("%d", &n);

    bool found = false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            found = true;
            printf("Numero %d divisibile per %d\n", n, i);
        }
    }

    if (!found) {
        printf("Numero %d primo\n", n);
    }
}

void lab2ex4(void) {
    const int side = 8;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (i == 0 || i == side - 1) {
                printf("#");
            } else {
                printf("%c", (j == 0 || j == side - 1) ? '#' : ' ');
            }
        }
        printf("\n");
    }
}

void lab2ex5(void) {
    const int n = 25;
    int prev_prev, prev = 0, curr = 1;
    
    printf("0\n");
    while(curr < n) {
        prev_prev = prev;
        prev = curr;
        curr = prev_prev + prev;
        
        printf("%d\n", prev);
    };
}

void lab2ex6(void) {
    const int height = 6;
    const int base = height * 2 - 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }

        for (int j = 0; j < base - (i * 2); j++) {
            printf("#");
        }

        printf("\n");
    }
}

int _pow(int base, int exponent) {
    int res = 1;
    while(exponent > 0) {
        res *= base;
        exponent -= 1;
    }
    return res;
}
 
void lab2ex7(void) {
    int base, exp;
    scanf("%d %d", &base, &exp);
    printf("%d\n", _pow(base, exp));
}