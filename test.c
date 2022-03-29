#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char course[4];
	char name[17];
	char id[33];
};

void Get_Lost(char*);
void find(FILE*, char* course);

int main()
{
	char course[4];
	FILE* file;
	file = fopen("Stud.txt", "rt");
	if (file == NULL)
		Get_Lost("Cannot open input file");
	printf("\nEnter the name of course,up to 3 letters: ");
	gets(course);
	find(file, course);
	fclose(file);

	return 0;
}

void find(FILE* file, char* course)
{
	struct Student temp;
	FILE* output;
	output = fopen("Output.txt", "w");
	if (output == NULL)
		Get_Lost("Cannot open output file");

	while (!feof(file))
	{
		fscanf(file, "%4s", temp.course);
		fgets(temp.course, 4, file);
		fgets(temp.id, 3, file);
		fgets(temp.name, 17, file);
		if (!strcmp(course, temp.course))
			printf("%s", temp.name);
	}

	fclose(output);
}

void Get_Lost(char* s)
{
	puts(s);
	exit(1);
}