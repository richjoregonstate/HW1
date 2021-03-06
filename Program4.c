/* CS261- HW1 - Program4.c*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(int n){
     /*Allocate memory for ten students*/
     struct student* class = malloc(n*sizeof(struct student));
     /*return the pointer*/
     return class;
}

void generate(struct student* students, int n){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z.
	The scores must be between 0 and 100*/
	int i;
  for (i = 0; i < n; i++) {
    students[i].initials[0] = rand()%(90+1 - 65)+65;/*ASCII code for a capatal letter*/
    students[i].initials[1] = rand()%(90+1 - 65)+65;
    students[i].score = rand()%100;
  }

}

void output(struct student* students,int n){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
		int i;
		for (i = 0; i < n; i++) {
			printf("%d", i);
			printf("%s", " ");
			printf("%s", (char*) students[i].initials);
			printf("%s", " ");
			printf("%d\n", students[i].score);
		}
    printf("%s\n", "--------");
}

void swap(struct student* a, struct student* b) {
	struct student t = *a;
	*a = *b;
	*b = t;
}

void sort(struct student* students, int n){
	int i, j;
	for (i = 0; i < n-1; i++){
			for (j = 0; j < n-i-1; j++){
				if (students[j].initials[0] == students[j+1].initials[0]) {
					if (students[j].initials[1] > students[j+1].initials[1]){
						swap(&students[j], &students[j+1]);
					}
				}
				else if (students[j].initials[0] > students[j+1].initials[0]){
					swap(&students[j], &students[j+1]);
				}
			}
		}
}


int main(){
		time_t seed = time(NULL);
		srand(seed);
    /*Declare an integer n and assign it a value.*/
    int n = rand()%100;
		assert(n > 0);
    /*Allocate memory for n students using malloc.*/
    struct student* stud;
    stud = allocate(n);
		assert(stud != NULL);
    /*Generate random IDs and scores for the n students, using rand().*/
    generate(stud,n);
    /*Print the contents of the array of n students.*/
    output(stud,n);
    /*Pass this array along with n to the sort() function*/
    sort(stud,n);
    /*Print the contents of the array of n students.*/
    output(stud,n);
    return 0;
}
