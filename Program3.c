/* CS261- HW1 - Program3.c*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
     int tmp,i,j;
     for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
          if (number[j] > number[j+1]) {
              tmp = number[j];
              number[j] = number[j+1];
              number[j+1] = tmp;
          }
        }
     }
}

int main(){
    srand(193482);
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i;
    if (n <= 0){
      return 1;
    }
    /*Allocate memory for an array of n integers using malloc.*/
    int *arr;
    arr = (int*) malloc(n*sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    for (i = 0; i < n; i++) {
      arr[i] = rand()%100;
    }
    /*Print the contents of the array.*/
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(arr,n);
    /*Print the contents of the array.*/
    printf("%s\n", "--------");
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
