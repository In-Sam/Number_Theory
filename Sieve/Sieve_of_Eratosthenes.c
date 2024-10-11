#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sqrt(int a);

int main() {

	// variables
	char form;
	int limit;
	int sqrt_limit;
	bool * sieve;
	int i, j;
	
	// form decision
	do {
		printf("which form do you want to watch? - (S)ieve, (P)rimes only :");
		scanf("%c", &form);
	} while ( ! ( form == 's' || form == 'S' || form == 'p' || form == 'P' ) );

	// limit decision
	do {
		printf("Until which number do you want to watch? : ");
		scanf("%d", &limit);
	} while ( limit <= 0 );

	// calculate
	sieve = (bool *)malloc((limit + 1) * sizeof(bool)); // sieve[n] means n is it prime?

	for ( i = 1; i <= limit; i++ ) {
		*(sieve + i) = true;
	}

	*(sieve + 1) = false; // 1 is not prime, 0 will not appear in the sieve.

	sqrt_limit = sqrt(limit);
	for ( i = 2; i < sqrt_limit; i++ ) {
		if ( *(sieve + i) ) { // Wasn't this number Erased?
			for ( j = 2; j*i <= limit; j++ ) // j : multiplier
				*(sieve + j*i) = false;
		}
	}

	// print
	switch(form) {
	case 's':
	case 'S':
		for ( i = 1; i <= limit; i++ )
			printf("\x1b[%dm%d\x1b[40m ", 41+*(sieve+i), i); 
		break;
	case 'p':
	case 'P':
		for ( i = 1; i <= limit; i++ ) {
			if ( *(sieve+i) )
				printf("%d ", i);
		}
		break;
	}

	printf("\x1b[40m");

	return 0;
}

int sqrt(int a) {
	int i;
	for ( i = 1; i*i < a; i++ )
		;
	return i;
}
