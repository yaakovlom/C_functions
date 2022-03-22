enum  WeekDays {
	Sunday = 1,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

char* weekdays_names[] = { [Sunday] = "Sunday", [Monday] = "Monday",
						[Tuesday] = "Tuesday", [Wednesday] = "Wednesday",
						[Thursday] = "Thursday", [Friday] = "Friday",
						[Saturday] = "Saturday" };

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

char* months_names[] = { [January] = "January", [February] = "February",
						[March] = "March", [April] = "April", [May] = "May",
						[June] = "June", [July] = "July", [August] = "August",
						[September] = "September", [October] = "October",
						[November] = "November", [December] = "December" };

enum Bool {
	False,
	True
};