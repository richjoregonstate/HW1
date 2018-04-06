/* CS261- HW1 - Program2.c*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
	int i;
  for (i = 0; i < 10; i++) {
    students[i].initials[0] = rand()%(90+1 - 65)+65;/*ASCII code for a capatal letter*/
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
		int i;
		for (i = 0; i < 10; i++) {
			printf("%d", i);
			printf("%s", " ");
			printf("%s", (char*) students[i].initials);
			printf("%s", " ");
			printf("%d\n", students[i].score);
		}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
		 int max = students[0].score;
 		 int min = students[0].score;
 		 int avg = 0;
		 int i;



		 for (i = 0; i < 10; i++) {
			 avg += students[i].score;
			 if (students[i].score > max) {
				 	max = students[i].score;
			 }
			 if (students[i].score < min) {
				 	min = students[i].score;
			 }
		 }
		 avg = avg/10;
		 printf("%s\n", "--------");
		 printf("%s", "Max: ");
		 printf("%d\n", max);
		 printf("%s", "Min: ");
		 printf("%d\n", min);
		 printf("%s", "Avg: ");
		 printf("%d\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
		 if (stud != NULL) {
			 	free(stud);
		 }
		 if(stud == NULL){
			 printf("%s\n", "Good to go");
		 }

}

int main(){
		struct student* stud = NULL;
		time_t seed = time(NULL);
		srand(seed);
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
