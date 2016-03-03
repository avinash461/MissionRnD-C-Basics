/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#pragma warning(disable:4996)
int len(char *str);
int is_leap(int num);
int isOlder(char *dob1, char *dob2) {
	int day1 = 0, day2 = 0, len1 = 0, len2 = 0, year1 = 0, year2 = 0, month1 = 0, month2 = 0, ye1_feb_days = 0, ye2_feb_days = 0;
	len1 = len(dob1);
	len2 = len(dob2);
	if (len1 && len2 == 10)
	{
		if ((dob1[2] && dob2[2] == '-') && (dob1[5] && dob2[5] == '-'))
		{

			year1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
			year2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
			month1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
			month2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
			day1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
			day2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
			//checking for leap years
			is_leap(year1) ? ye1_feb_days = 29 : ye1_feb_days = 28;
			is_leap(year2) ? ye2_feb_days = 29 : ye2_feb_days = 28;
			if ((month1 && month2) <= 12 && (day1 && day2) <= 31)
			{
				if ((month1 == 1) && (day1 <= 31) || (month1 == 3) && (day1 <= 31) || (month1 == 5) && (day1 <= 31) || (month1 == 7) && (day1 <= 31) || (month1 == 8) && (day1 <= 31) ||
					(month1 == 10) && (day1 <= 31) || (month1 == 12) && (day1 <= 31) || (month1 == 4) && (day1 <= 30) || (month1 == 6) && (day1 <= 30) || (month1 == 9) && (day1 <= 30) || (month1 == 11) && (day1 <= 30)
					|| (month1 == 2) && (day1 <= ye1_feb_days))
				{

					if ((month2 == 1) && (day2 <= 31) || (month2 == 3) && (day2 <= 31) || (month2 == 5) && (day2 <= 31) || (month2 == 7) && (day2 <= 31) || (month2 == 8) && (day2 <= 31) ||
						(month2 == 10) && (day2 <= 31) || (month2 == 12) && (day2 <= 31) || (month2 == 4) && (day2 <= 30) || (month2 == 6) && (day2 <= 30) || (month2 == 9) && (day2 <= 30) || (month2 == 11) && (day2 <= 30)
						|| (month2 == 2) && (day2 <= ye1_feb_days))
						//if((month2==(1||3||5||7||8||10||12) && day2<=31) || (month2==(4||6||9||11) && day2<=30)||(month2==2 && day2<=ye2_feb_days))
					{
						if (year1 == year2)
						{
							if (month1 == month2)
							{
								if (day1 == day2)
								{
									return 0;
								}
								else return day1>day2 ? 2 : 1;
							}
							else return month1>month2 ? 2 : 1;
						}
						else return year1>year2 ? 2 : 1;

					}
					else return -1;
				}
				else return -1;
			}
			else return -1;

		}
		else return -1;
	}
	else return -1;
}
//function return the length of the date
int len(char *str)
{
	int length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return length;
}
//function for checking leap year or not
int is_leap(int num)
{
	if (((num % 4 == 0) && (num % 100 != 0)) || (num % 400 == 0))
	{
		return 1;
	}
	else return 0;
}
