#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4


// *** arrays ***

void print_matrix(int* arr[N])
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
			printf("%d ", arr[r][c]);
		printf("\n");
	}
}

void print_array(int* arr, int len)
{
	printf("The array is: ");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void copy_array(int dist[N][N], int src[N][N])
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			dist[r][c] = src[r][c];
}

void putInOrder(int* arr, int len, int input)
{
	int end = len - 1;
	arr[end] = input;
	while (arr[end - 1] > arr[end] && end) {
		swap(arr + end, arr + end - 1);
		end--;
	}
}

void spin_array_right(int arr[][N])
{
	int _arr[N][N];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			_arr[r][c] = arr[N - 1 - c][r];
	copy_array(arr, _arr);
}

void spin_array_left(int arr[][N])
{
	int _arr[N][N];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			_arr[r][c] = arr[c][N - 1 - r];
	copy_array(arr, _arr);
}

// *** bits ***

int set_bit(int num, int bit)
{
	int mask = 1;
	mask <<= bit;
	num |= mask;
	return num;
}

int check_bits(int num, int bits)
{
	return (num & bits) == bits;
}

// *** checks ***

int is_digit(char cha)
{
	return (cha >= '0') && (cha <= '9');
}

int is_space(char ch)
{
	return (ch == '\t' || ch == ' ');
}


// *** strings ***

int str_find_digit(char string[])
{
	int *p = string;
	while (*string && (!is_digit(*string)))
		string++;
	return *string ? string : NULL;
}

int str_count_ch(char string[], char ch)
{
	int count = 0;
	while (*string)
	{
		if (*string == ch)
			count++;
		string++;
	}
	return count;
}

int my_strchr(char string[], char ch)
{
	int* p = string;
	while (*string && !(*string == ch))
		string++;
	return *string ? string : NULL;
}

int my_strlen(char string[])
{
	int count = 0;
	while (*string)
	{
		count++;
		string++;
	}
	return count;
}

int my_strcmp(char* str1, char* str2)
{
	while (!(*str1 - *str2) && (*str1++ && *str2++));
	return (*str1 - *str2 > 0) - (*str1 - *str2 < 0);
}

int my_strncmp(char* str1, char* str2, int n)
{
	int cmp, count = 0;
	while ((count < n) && !(cmp = *str1 - *str2) && (*str1++ && *str2++))
		count++;
	return (cmp > 0) - (cmp < 0);
}

int my_strstr(char *str1, char *str2)
{
	int *find = str2;
	while ((*str1))
	{
		while (*str2 == *str2)
		{
		}
		str1++;
	}
	return find == str2 ? NULL : str1;
}

char my_strpbrk(char* str, char* str2)
{
	for (int i = 0; i < strlen(str); i++)
		for (int j = 0; j < strlen(str2); j++)
			if (str[i] == str2[j])
				return str[i];
	return NULL;
}