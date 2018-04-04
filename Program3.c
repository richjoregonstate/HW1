/* CS261- HW1 - Program3.c*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/
}

int main(){
    time_t t;
    srand((unsigned) time(&t));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *arr;
    if (n > 0) {
      arr = (int*) malloc(n*sizeof(int));
    }
    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i++) {
      arr[i] = rand()%100;
    }
    /*Print the contents of the array.*/
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(arr,n);
    /*Print the contents of the array.*/
    printf("%s\n", "--------");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
