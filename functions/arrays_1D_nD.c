#include "funcs_for_all.h"

#define N 5

// print int array
void print_array(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%3d ", arr[i]);
	printf("\n");
}

// print int matrix (functions to add: print_array)
void print_matrix(int **arr, int row_len, int col_len)
{
	for (int i = 0; i < row_len; i++)
		print_array(arr[i], col_len);
}

// copy array to the scened
void copy_array(int dist[N][N], int src[N][N])
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			dist[r][c] = src[r][c];
}

// add int into array in the right order (functions to add: swap)
void put_in_order(int* arr, int len, int input)
{
	int end = len - 1;
	arr[end] = input;
	while (arr[end - 1] > arr[end] && end) {
		swap(arr + end--, arr + end);
	}
}

// check if the index is in the range
int is_in_array(int arr[N][N], int row, int col)
{
	if ((row < 0 || row >= N) || (col < 0 || col >= N))
		return 0;
	return 1;
}

// spin the array clockwise (functions to add: copy_array)
void spin_array_right(int arr[][N])
{
	int _arr[N][N];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			_arr[r][c] = arr[N - 1 - c][r];
	copy_array(arr, _arr);
}

// spin the array counterclockwise (functions to add: copy_array)
void spin_array_left(int arr[][N])
{
	int _arr[N][N];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			_arr[r][c] = arr[c][N - 1 - r];
	copy_array(arr, _arr);
}

// compare columns of an int matrix
int compare_columns(int arr[][N], int col1, int col2)
{
	for (int i = 0; i < N; i++)
		if (arr[i][col1] != arr[i][col2])
			return (arr[i][col1] < arr[i][col2]) - (arr[i][col1] > arr[i][col2]);// return 1 / -1
	return 0;
}

// sort an int array (functions to add: swap)
void sort_array(int arr[], int len)
{
	int c, * p;
	for (c = 1; c < len; c++)
	{
		p = arr+c;
		while (p > arr && *p < *(p - 1))
		{
			swap(p, (p - 1));
			p--;
		}
	}
}

// sort column of int matrix (functions to add: swap)
void sort_column(int arr[][N], int rows_len, int col)
{
	int i;
	for (int r = 1; r < rows_len; r++)
	{
		i = r;
		while (i > 0 && arr[i][col] < arr[i - 1][col])
		{
			swap(&arr[i][col], &arr[i - 1][col]);
			i--;
		}
	}
}

// swap columns of a matrix (functions to add: swap)
void swap_columns(int arr[][N], int col1, int col2)
{
	for (int row = 0; row < N; row++)
		swap(&arr[row][col1], &arr[row][col2]);
}
