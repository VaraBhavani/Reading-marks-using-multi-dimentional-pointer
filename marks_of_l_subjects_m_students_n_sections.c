// Read and print marks of l subjects of m sections of n students //

#include <stdio.h>
#include <stdlib.h>

int ***read_marks()
{
	int ***marks;
	int subjects_count, subject_counter, students_count, student_counter, sections_count, section_counter;
	printf("Enter number of sections are there: ");
	scanf("%d", &sections_count);
	printf("Enter number of students in each section: ");
	scanf("%d", &students_count);
	printf("Enter number of subjects for each student: ");
	scanf("%d", &subjects_count);
	marks = (int***)malloc((sections_count + 3) * sizeof(int**));
	marks[0] = (int **)malloc(sizeof(int*));
	marks[1] = (int **)malloc(sizeof(int*));
	marks[2] = (int **)malloc(sizeof(int*));

	*marks[0] = (int *)malloc(sizeof(int));
	*marks[1] = (int *)malloc(sizeof(int));
	*marks[2] = (int *)malloc(sizeof(int));

	*(*(marks[0])) = sections_count;
	*(*(marks[1])) = students_count;
	*(*(marks[2])) = subjects_count;

	for (section_counter = 3; section_counter < sections_count + 3; section_counter++)
	{
		*(marks + section_counter) = (int**)malloc(students_count * sizeof(int*));
		for (student_counter = 0; student_counter < students_count; student_counter++)
		{
			*(*(marks + section_counter)+student_counter) = (int*)malloc(subjects_count * sizeof(int));
		}
	}
	
	for (section_counter = 3; section_counter < sections_count + 3; section_counter++)
	{
		for (student_counter = 0; student_counter < students_count; student_counter++)
		{
			for(subject_counter = 0; subject_counter < subjects_count; subject_counter++)
			{
				printf("Enter marks of student %d of section %d in subject %d: ", student_counter + 1, section_counter - 2, subject_counter + 1);
				scanf("%d",*(*(marks + section_counter) + student_counter) + subject_counter);
			}
		}
	}
	return marks;
}

int main()
{
	int ***marks;
	marks = read_marks();
	int subjects_count, subject_counter, students_count, student_counter, sections_count, section_counter;
	sections_count = **marks[0];
	students_count = **marks[1];
	subjects_count = **marks[2];
	for (section_counter = 0; section_counter < sections_count; section_counter++)
	{
		printf("\nMarks of section %d students are: \n", section_counter + 1);
		for (student_counter = 0; student_counter < students_count; student_counter++)
		{
			printf("\nMarks of student %d in section %d are: \n", student_counter + 1, section_counter + 1);
			for (subject_counter = 0; subject_counter < subjects_count; subject_counter++)
			{
				printf("marks of student %d in subject %d is %d. \n", student_counter + 1, subject_counter + 1, *(*(*(marks + (section_counter + 3)) + student_counter) + subject_counter));
			}
		}
	}
}