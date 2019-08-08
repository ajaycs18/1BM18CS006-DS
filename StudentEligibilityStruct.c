#include <stdio.h>

struct Student {
	int id, age, marks;
};

int main() {
	int i;
	struct Student student;
	printf("Enter student id, age & marks: ");
	scanf("%d %d %d", &student,id, &student.age, &student.marks);
	if (students[i].age > 20 && students[i].marks >= 65 && students[i].marks <= 100)
		printf("Student %d is Valid and Qualifies\n", i + 1);
	else printf("Student %d is not Valid and does not Qualify\n", i + 1);
	
	getchar();
	return 0;
}
