#include <stdio.h>

struct Student {
	int id, age, marks;
};

int main() {
	int n, i;
	printf("Enter number of students: ");
	scanf("%d", &n);
	struct Student students[n];
	for (i = 0; i < n; ++i) {
		printf("Enter student %d id, age & marks: ", i + 1);
		scanf("%d %d %d", &students[i].id, &students[i].age, &students[i].marks);

		if (students[i].age > 20 && students[i].marks >= 65 && students[i].marks <= 100)
			printf("Student %d is Valid and Qualifies\n", i + 1);
		else printf("Student %d is not Valid and does not Qualify\n", i + 1);
	}
	
	getchar();
	return 0;
}
