#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define CHUNK 10

// convert a digit char to an int (functions to add: is_digit, <assert.h>)
short int char_to_int(char ch)
{
	assert(is_digit(ch));
	return ch - '0';
}

// set the string and clean the STDIN
void after_gets(char *str)
{
	int ch = 0;
	if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
	else while ((ch = getchar()) != '\n' && ch != EOF);
}

// get non formating string
char* get_string()
{
	char* input = NULL;
	char tempbuf[CHUNK];
	int inputlen = 0, templen = 0;
	do {
		fgets(tempbuf, CHUNK, stdin);
		templen = strlen(tempbuf);
		input = realloc(input, inputlen + templen + 1);
		strcpy(input + inputlen, tempbuf);
		inputlen += templen;
	} while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');
		input[strlen(input) - 1] = '\0';
		return input;
}

// find the first digit in the string
int str_find_digit(char string[])
{
	int *p = string;
	while (*string && (!is_digit(*string)))
		string++;
	return *string ? string : NULL;
}

// count the occurrences of the char in the string
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

// find the first occurrences of the char in the string
char my_strchr(char string[], char ch)
{
	int* p = string;
	while (*string && !(*string == ch))
		string++;
	return *string ? string : NULL;
}

// my strlen function
int my_strlen(char* str)
{
	int count = 0;
	while (*str++)
		count++;
	return count;
}

// my strcmp function
int my_strcmp(char* str1, char* str2)
{
	while (!(*str1 - *str2) && (*str1++ && *str2++));
	return (*str1 - *str2 > 0) - (*str1 - *str2 < 0);
}

// my strncmp function
int my_strncmp(char* str1, char* str2, int n)
{
	int cmp, count = 0;
	while ((count < n) && !(cmp = *str1 - *str2) && (*str1++ && *str2++))
		count++;
	return (cmp > 0) - (cmp < 0);
}

// my strstr function
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

// my strstr function
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
char *replace_str(const char *src, const char *old, const char *_new)
{
	size_t src_len = strlen(src);
    size_t old_len = strlen(old);
    size_t new_len = strlen(_new);
    size_t old_count = count_str_str(src, old);

    char *ret = (char *)malloc((src_len - ((old_len - new_len) * old_count) + 1) * sizeof(char));
	if (!ret)
		return NULL;
    char *ret_p = ret;
    char *next_strstr = strstr(src, old);

    while (*src)
        // if at start of old occurrence
        if (src == next_strstr)
        {
            // insert the new sub-string
            strncpy(ret_p, _new, new_len);
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
	free(src);
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
	if (!strs_lens)
		return NULL;
    size_t i;
    // overall length
    for (i = 0; i < n_strs; i++)
    {
        strs_lens[i] = strlen(strs[i]);
        overall_len += strs_lens[i];
    }

    char *ret = (char *)malloc((overall_len + joiner_len * (n_strs - 1)) * sizeof(char));
	if (!ret)
		return NULL;
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

	//			*** string checks ***

	int is_digit(char cha)
	{
		return (cha >= '0') && (cha <= '9');
	}

	int is_haigh_char(char cha)
	{
		return (cha >= 'A') && (cha <= 'Z');
	}

	int is_low_char(char cha)
	{
		return (cha >= 'a') && (cha <= 'z');
	}

	int is_space(char ch)
	{
		return (ch == '\t' || ch == ' ');
	}
