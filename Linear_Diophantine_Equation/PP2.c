#include <stdio.h>

int main() {
	int k;
	int m, w, c;
	for ( k = -1000; k < 1000; k++ ) {
		m = -100 + 3 * k;
		w = 200 - 5 * k;
		c = 2 * k;
		if ( m > 0 && w > 0 && c > 0 ) {
			printf("m : %d, w : %d, c : %d for k = %d\n", m, w, c, k);
		}
	}
	return 0;
}
