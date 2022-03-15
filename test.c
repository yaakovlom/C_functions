#include <stdio.h>
#include <stdlib.h>

#define N 20

int strlen(char* str) {
	int count = 0;
	while (*str++)
		count++;
	return count;
}

void remove_new_line(char* str)
{
	int* end = str + strlen(str) - 1;
	if (*end == '\n') *end = '\0';
}

int is_digit(char cha)
{
	return (cha >= '0') && (cha <= '9');
}

char* get_string(char *str, int len)
{
	int clean;
	str = malloc((len + 1) * sizeof(char));
	printf("Enter string <20 chars>: ");
	scanf("%d", &clean);
	fgets(str, len, stdin);
	remove_new_line(str);
	return str;
}

char* zippedString(char* str)
{
	int len = strlen(str), zip_len = len, count = 1;

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
	int count = 0, len = strlen(str), flag = 0;
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
	printf("%s", str);
	do
	{
		printf("What to do? (1=zip, 2=unzip, 3=change string, 4=finish):");
		scanf("%d", &res);
		switch (res)
		{
		case 1:
			str = zippedString(str);
			printf("%s", str);
			break;
		case 2:
			str = unzipString(str);
			printf("%s", str);
			break;
		case 3:
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