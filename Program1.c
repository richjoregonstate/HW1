/* CS261- HW1 - Program1.c*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    printf("%u\n", *a);
    printf("%u\n", *b);
    printf("%u\n", c);
    printf("%s\n","------" );
    /* Increment a */
    (*a)++;
    /* Decrement  b */
    (*b)--;
    /* Assign a-b to c */
    c = (*a)-(*b);
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    time_t seed = time(NULL);
    srand(seed);

    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    int *z = malloc(sizeof(int));
    int *fooBar = malloc(sizeof(int));

    *x = rand()%10;
    *y = rand()%10;
    *z = rand()%10;

    /* Print the values of x, y and z */
    printf("%d\n", *x);
    printf("%d\n", *y);
    printf("%d\n", *z);
    printf("%s\n","------" );

    /* Call foo() appropriately, passing x,y,z as parameters */
    *fooBar = foo(x,y,*z);

    /* Print the values of x, y and z */
    printf("%d\n", *x);
    printf("%d\n", *y);
    printf("%d\n", *z);
    printf("%s\n","------" );

    /* Print the value returned by foo */
    printf("%d\n", *fooBar);
    /* Is the return value different than the value of z?  Why? */
    return 0;
}
