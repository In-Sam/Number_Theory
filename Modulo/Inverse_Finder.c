#include <stdio.h>

int main() {
    int e, a;
    int q, r;
    int rev[4][100];
    int stack1, stack2;
    int count = 0;
    int temp;
    int oe, oa;
   
    scanf("%d %d", &e, &a);
   
    if ( e < a ) {
        temp = e;
        e = a;
        a = temp;
    }
   
    oe = e;
    oa = a;
   
    r = -1;
    while ( r ) {
        q = e/a;
        r = e - a * q;
        printf("%d = %d * %d + %d\n", e, a, q, r);
        rev[0][count] = e;
        rev[1][count] = a;
        rev[2][count] = q;
        rev[3][count] = r;
       
        e = a;
        a = r;
        count++;
    }
   
    stack1 = 1;
    stack2 = -rev[2][count-2];
    printf("\n%dx + %dy = %d\n= %d*%d + %d*%d\n", oe, oa, rev[1][count-1], rev[0][count-2], stack1, rev[1][count-2], stack2);
   
    for ( int i = 3; i <= count; i++ ) {
       
        temp = stack1;
        stack1 = stack2;
        stack2 = temp;
       
        stack2 -= rev[2][count-i] * stack1;
        printf("= %d*%d + %d*%d\n", rev[0][count-i], stack1, rev[1][count-i], stack2);
       
    }
   
    return 0;
}
