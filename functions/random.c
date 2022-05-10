#include <stdlib.h>

// add the PCU time to random function (functions to add: <stdlib.h>)
void set_random_seed()
{
	time_t t;
	srand((unsigned)time(&t));
}

// fill array with random values
void init_random_array(int* arr, int arr_len, int max)
{
	for (int i = 0; i < arr_len; i++)
		arr[i] = rand() % max;
}
