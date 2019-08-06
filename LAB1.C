#include <stdio.h>
#include <conio.h>
struct marks {
  float LD;
  float COA;
  float DS;
  float DM;
  float MP;
  float PW;
  float NC;
  float CIPE;
  float JAVA;
};

void showMarks(struct marks s) {
   printf("\n\nMarks of the Student are:\n");
   printf("Logic Design (LD): %f\n", s.LD);
   printf("Computer Architecture & Design (COA): %f\n", s.COA);
   printf("Data Structures (DS): %f\n", s.DS);
   printf("Discrete Mathematics (DM): %f\n", s.DM);
   printf("Microprocessors & Microcontrollers (MP): %f\n", s.MP);
   printf("Project Work (PW): %f\n", s.PW);
   printf("Physical Activity (NC): %f\n", s.NC);
   printf("Constitution of India (CIPE): %f\n", s.CIPE);
   printf("OOP with Java (JAVA): %f\n", s.JAVA);
}

void getMarks(struct marks *s) {
	printf("Enter your marks for the below subjects:\n");
	printf("Logic Design (LD): ");
	scanf("%f", s->LD);
	printf("Computer Architecture & Design (COA): ");
	scanf("%f", s->COA);
	printf("Data Structures (DS): ");
	scanf("%f", s->DS);
	printf("Discrete Mathematics (DM): ");
	scanf("%f", s->DM);
	printf("Microprocessors & Microcontrollers (MP): ");
	scanf("%f", s->MP);
	printf("Project Work (PW): ");
	scanf("%f", s->PW);
	printf("Physical Activity (NC): ");
	scanf("%f", s->NC);
	printf("Constitution of India (CIPE): ");
	scanf("%f", s->CIPE);
	printf("OOP with Java (JAVA): ");
	scanf("%f", s->JAVA);
}

void main() {
	struct marks student;
	clrscr();
	getMarks(&student);
	showMarks(student);
	getch();
	getch();

}