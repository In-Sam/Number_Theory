#include <stdio.h>

int main() {
	int k;
	int x, y, z;
	for ( k = -1000; k < 1000; k++ ) {
		x = -300 + 5 * k;
		y = 1200 - 19 * k;
		z = 14 * k - 800;
		if ( x > 0 && y > 0 && z > 0 ) {
			printf("x : %d, y : %d, z : %d for k = %d\n", x, y, z, k);
		}
	}
	return 0;
}
