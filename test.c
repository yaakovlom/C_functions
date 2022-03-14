#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int *arr = malloc(0), input, len = 0;
	do
	{
		printf("Enter an integer to the array: ");
		if (scanf("%d", &input) && (arr = realloc(arr, ++len * sizeof(int))) && input > 0) {
			putInOrder(arr, len, input);
			print_array(arr, len);
		}
	} while (input > 0 && arr);

	return 0;
}