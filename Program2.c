/* CS261- HW1 - Program2.c*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* class = malloc(10*sizeof(struct student));
     /*return the pointer*/
     return class;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z.
	The scores must be between 0 and 100*/
  for (size_t i = 0; i < 10; i++) {
    students[i].initials[0] = rand()%(90+1 - 65)+65;//ASCII code for a capatal letter
    students[i].initials[1] = rand()%(90+1 - 65)+65;
    students[i].score = rand()%100;
  }

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
		for (size_t i = 0; i < 10; i++) {
			printf("%d", i);
			printf("%s", " ");
			printf("%s", (char*) students[i].initials);
			printf("%s", " ");
			printf("%d\n", students[i].score);
		}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
		 for (size_t i = 0; i < 10; i++) {
		 	free(stud[i]);
		 }
		 if(stud == NULL){
			 printf("%s\n", "Good to go");
		 }
}

int main(){
    time_t t;
    srand((unsigned) time(&t));
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
		output(stud);
    /*call summary*/
		summary(stud);
    /*call deallocate*/
		deallocate(stud);
    return 0;
}
