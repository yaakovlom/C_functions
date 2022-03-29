#define N 5

#define ADD_TO_STRING(str) #str


//				*** general ***
void swap(int* a, int* b);

//				*** random ***
void set_random_seed();
void init_random_array(int* arr, int arr_len, int max);

//				*** arrays ***
void print_array(int* arr, int len);
void print_matrix(int** arr, int rows, int columns);
void copy_array(int dist[N][N], int src[N][N]);
void put_in_order(int* arr, int len, int input);
int is_in_array(int arr[N][N], int row, int col);
void spin_array_right(int arr[][N]);
void spin_array_left(int arr[][N]);
int compare_columns(int arr[][N], int col1, int col2);
void sort_array(int arr[], int len);
void sort_column(int arr[][N], int rows_len, int col);
void swap_columns(int arr[][N], int col1, int col2);

//				*** bits ***
int set_bit(int num, int bit);
int check_bits(int num, int bits);

//				*** strings ***
short int char_to_int(char ch);
void after_gets(char* str);
char* get_string();
int str_find_digit(char string[]);
int str_count_ch(char string[], char ch);
char my_strchr(char string[], char ch);
int my_strlen(char* str);
int my_strcmp(char* str1, char* str2);
int my_strncmp(char* str1, char* str2, int n);
int my_strstr(char* str1, char* str2);
char my_strpbrk(char* str, char* str2);
size_t count_str_str(const char* src, const char* sub_str);
char* replace_str(const char* src, const char* old, const char* );
char* capitalize(char* str);
int str_endswith(const char* str, const char* sub_str);
char* str_join(const char* joiner, char* strs[], size_t n_strs);

//			*** string checks ***
int is_digit(char cha);
int is_haigh_char(char cha);
int is_low_char(char cha);
int is_space(char ch);


enum  WeekDays {
	Sunday = 1,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

//char* weekdays_names[] = { [Sunday] = "Sunday",[Monday] = "Monday",
//						[Tuesday] = "Tuesday",[Wednesday] = "Wednesday",
//						[Thursday] = "Thursday",[Friday] = "Friday",
//						[Saturday] = "Saturday" };

enum Months {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

//char* months_names[] = { [January] = "January",[February] = "February",
//						[March] = "March",[April] = "April",[May] = "May",
//						[June] = "June",[July] = "July",[August] = "August",
//						[September] = "September",[October] = "October",
//						[November] = "November",[December] = "December" };

enum Bool {
	False,
	True
};