#include <stdio.h>
#include <stdlib.h>

/* find prime number upto 100 */
void findFrimeNumber() {
    int *prime = (int *)calloc(sizeof(int), 101);
    for (int i = 2; i <= 100; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;

    for (int p = 2; p*p <= 100; p++) {
        if (prime[p]) {
            for (int i = p*p; i <= 100; i += p)
                prime[i] = 0;
        }
    }

    printf("The prime Number: upto 100\n");
    for (int i = 2; i <= 100; i++)
        if(prime[i]) printf("%d ", i);
    
    printf("\n");
}


int main () {
    findFrimeNumber();
}