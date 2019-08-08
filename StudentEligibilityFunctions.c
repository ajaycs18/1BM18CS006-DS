#include <stdio.h>

struct Student {
	int id, age, marks;
};

int validate(struct Student s) {
	if(s.age > 20 && s.marks >= 0 && s.marks <= 100)
		return 1;
	else
		return 0;
}

int qualify(struct Student s) {

	if (validate(s)) {
		if (s.marks >= 65)
			return 1;
		else
			return 0;
	}
	else 
		return 0;
}

int main() {
	int n, i;
	printf("Enter number of students: ");
	scanf("%d", &n);
	struct Student students[n];
	for (i=0; i < n; i++) {
		printf("Enter id, age & marks: ");
		scanf("%d %d %d", &students[i].id, &students[i].age, &students[i].marks);
		if (qualify(students[i])) 
			printf("Student %d is Eligible\n", i + 1);
		else 
			printf("Student %d is not Eligible\n", i + 1);
	}
	
	getchar();
	return 0;
}
