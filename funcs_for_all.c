#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

// *** general ***
void swap(int* a, int* b);

// *** random ***
void set_random_seed();
void random_array(int* arr, int arr_len, int max);

// *** arrays ***
void print_array(int* arr, int len);
void print_matrix(int** arr, int rows, int columns);
void copy_array(int dist[N][N], int src[N][N]);
void put_in_order(int* arr, int len, int input);
int is_in_array(int arr[N][N], int row, int col);
void spin_array_right(int arr[][N]);
void spin_array_left(int arr[][N]);

// *** bits ***
int set_bit(int num, int bit);
int check_bits(int num, int bits);

// *** checks ***
int is_digit(char cha);
int is_space(char ch);

// *** strings ***
void after_gets(char* str);
char* get_string(char* str, int len);
int str_find_digit(char string[]);
int str_count_ch(char string[], char ch);
int my_strchr(char string[], char ch);
int my_strlen(char* str);
int my_strcmp(char* str1, char* str2);
int my_strncmp(char* str1, char* str2, int n);
int my_strstr(char* str1, char* str2);
char my_strpbrk(char* str, char* str2);
size_t count_str_str(const char *src, const char *sub_str);
char *replace_str(const char *src, const char *old, const char *new);
char *capitalize(char *str);
int str_endswith(const char *str, const char *sub_str);
char *str_join(const char *joiner, char *strs[], size_t n_strs);


// *** general ***

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// *** random ***

void set_random_seed()
{
	time_t t;
	srand((unsigned)time(&t));
}

void init_random_array(int* arr, int arr_len, int max)
{
	for (int i = 0; i < arr_len; i++)
		arr[i] = rand() % max;
}


// *** arrays ***

void print_array(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%3d ", arr[i]);
	printf("\n");
}

void print_matrix(int **arr, int row_len, int col_len)
{
	for (int i = 0; i < row_len; i++)
		print_array(arr[i], col_len);
}

void copy_array(int dist[N][N], int src[N][N])
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			dist[r][c] = src[r][c];
}

void put_in_order(int* arr, int len, int input)
{
	int end = len - 1;
	arr[end] = input;
	while (arr[end - 1] > arr[end] && end) {
		swap(arr + end--, arr + end);
	}
}

int is_in_array(int arr[N][N], int row, int col)
{
	if ((row < 0 || row >= N) || (col < 0 || col >= N))
		return 0;
	return 1;
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

void after_gets(char *str)
{
	int ch = 0;
	if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
	else while ((ch = getchar()) != '\n' && ch != EOF);
}

char* get_string(char* str, int len)
{
	str = malloc((len + 1) * sizeof(char));
	printf("Enter string <%d chars>: ", len);
	fgets(str, len + 1, stdin);
	after_gets(str);
	return str;
}

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

int my_strlen(char* str)
{
	int count = 0;
	while (*str++)
		count++;
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

/*
 * Return the number of non-overlapping occurrences
 * of substring sub_str in string src.
 */
size_t count_str_str(const char *src, const char *sub_str)
{
    size_t count = 0;
    size_t sub_str_len = strlen(sub_str);
    while ((src = strstr(src, sub_str)) != NULL)
    {
        count++;
        src += sub_str_len;
    }
    return count;
}

// Return a copy with all occurrences of substring old replaced by new
char *replace_str(const char *src, const char *old, const char *new)
{
	size_t src_len = strlen(src);
    size_t old_len = strlen(old);
    size_t new_len = strlen(new);
    size_t old_count = count_str_str(src, old);

    char *ret = (char *)malloc((src_len - ((old_len - new_len) * old_count) + 1) * sizeof(char));
    char *ret_p = ret;
    char *next_strstr = strstr(src, old);

    while (*src)
        // if at start of old occurrence
        if (src == next_strstr)
        {
            // insert the new sub-string
            strncpy(ret_p, new, new_len);
            // jump over this occurrence
            src += old_len;
			// search for the next occurrence
			next_strstr = strstr(src, old);
            // move the return pointer to the end
			ret_p += new_len;
        }
        // another char
        else
            *ret_p++ = *src++;
    
    *ret_p = '\0';
    return ret;
}

// make the first character have upper case and the rest lower case.
char *capitalize(char *str)
{
    char *str_p = str;
    *str_p = toupper(*str_p);
    while (*++str_p)
        *str_p = tolower(*str_p);
    return str;
}

int str_endswith(const char *str, char const *sub_str)
{
    size_t str_len = strlen(str);
    size_t sub_str_len = strlen(sub_str);

    return strncmp(str + str_len - sub_str_len, sub_str, sub_str_len) == 0;
}

// Concatenate any number of strings with the joiner string in-betwin
char *str_join(const char *joiner, char *strs[], size_t n_strs)
{
    if (n_strs < 2)
        return strs[0];

    size_t joiner_len = strlen(joiner);
    size_t overall_len = 0;
    size_t *strs_lens = (size_t *)malloc(n_strs * sizeof(size_t));
    size_t i;
    // overall length
    for (i = 0; i < n_strs; i++)
    {
        strs_lens[i] = strlen(strs[i]);
        overall_len += strs_lens[i];
    }

    char *ret = (char *)malloc((overall_len + joiner_len * (n_strs - 1)) * sizeof(char));
    char *ret_p = ret;

    // insert the first string
    strncpy(ret_p, strs[0], strs_lens[0]);
    // jump to the current end
    ret_p += strs_lens[0];

    for (size_t i = 1; i < n_strs; i++)
    {
        // insert the joiner to ret
        strncpy(ret_p, joiner, joiner_len);
        // jump to the current end
        ret_p += joiner_len;
        // insert the current string
        strncpy(ret_p, strs[i], strs_lens[i]);
        // jump to the current end
        ret_p += strs_lens[i];
    }
    
    *ret_p = '\0';
    free(strs_lens);
    return ret;
}
