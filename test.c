#include <stdio.h>
#include <stdlib.h>

#define N 7

char* zippedString(char* str)
{
	int len = my_strlen(str), zip_len = len, count = 1;

	for (int i = 2; i < len; i++)
		if (*(str + i) == *(str + i - 1) && *(str + i) == *(str + i - 2))
			zip_len--;
	char* new_str = malloc(zip_len * sizeof(char)), * p_new_str = new_str;
	new_str[zip_len] = '\0';
	
	while (*p_new_str)
	{
		if (*str == *(str + 1))
			count++;
		else
		{
			if (count != 1)
				*p_new_str++ = count + '0';
			*p_new_str++ = *str;
			count = 1;
		}
		str++;
	}
	return new_str;
}

char* unzipString(char* str)
{
	int count = 0, len = my_strlen(str), flag = 0;
	for (int i = 0; i < len; i++)
		if (is_digit(*(str + i)))
			count += *(str + i) - '0' - 2;

	char *new_str = malloc((count + len + 1) * sizeof(char)), *p_new_str = new_str;
	new_str[count + len] = '\0';
	while (*p_new_str)
	{
		if (is_digit(*str))
		{
			flag = (*str - '0' - 1);
			str++;
		}
		else
		{
			*p_new_str++ = *str;
			if (flag)
				flag--;
			else
				str++;
		}
	}
	return new_str;
}

int main()
{
	char* str = NULL;
	int finish = 0, res;

	str = get_string(str, N);
	do
	{
		printf("What to do? (1=zip, 2=unzip, 3=change string, 4=finish):");
		flush_all();
		scanf(" %d", &res);
		switch (res)
		{
		case 1:
			str = zippedString(str);
			printf("%s\n", str);
			break;
		case 2:
			str = unzipString(str);
			printf("%s\n", str);
			break;
		case 3:
			flush_all();
			str = get_string(str, N);
			break;
		case 4:
			finish = 1;
			break;
		default:
			break;
		}
	} while (!finish);

	free(str);
	printf("Goodbye..");
	return 0;
}

int main1()
{
	int **arr = malloc(N * sizeof(int*));
	set_random_seed();
	for (int i = 0; i < N; i++)
	{
		arr[i] = malloc(N * sizeof(int));
		init_random_array(arr[i], N, 20);
	}
	print_matrix(arr, N, N);
	printf("\n");
	for (int i = 0; i < N; i++)
		matrix_sort_columns(arr, i, N, N);
	print_matrix(arr, N, N);
}