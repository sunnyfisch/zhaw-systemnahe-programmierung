 /* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab P02 weekday
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// *** TASK1: typedef enum types for month_t (Jan=1,...Dec} ***
// BEGIN-STUDENTS-TO-ADD-CODE
 typedef enum  {JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ} month_t;
// END-STUDENTS-TO-ADD-CODE



// *** TASK1: typedef struct for date_t ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {
    int year;
    month_t month;
    int day;
} date_t;
// END-STUDENTS-TO-ADD-CODE



// *** TASK2: typedef enum weekday_t (Sun=0, Mon, ...Sat) ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef enum {SUN=0, MON, TUE, WED, THU, FRI, SAT} weekday_t;
// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
// BEGIN-STUDENTS-TO-ADD-CODE
 int is_leap_year(date_t date) {
     if ((date.year % 4) == 0 && (date.year % 100 != 0) ) {
         return 1;
     } else if ((date.year % 400 == 0)) {
         return 1;
     } else {
         return 0;
     }
 }
// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
// BEGIN-STUDENTS-TO-ADD-CODE
 int get_month_length(date_t date) {
     switch (date.month) {
         case JAN:
         case MAR:
         case MAI:
         case JUL:
         case AUG:
         case OKT:
         case DEZ:
             return 31;
         case FEB:
             return is_leap_year(date) ? 29 : 28;
         case APR:
         case JUN:
         case SEP:
         case NOV:
             return 30;
         default:
             return 0;
     }
 }
// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
// BEGIN-STUDENTS-TO-ADD-CODE
 int is_gregorian_date(date_t date) {
     if (date.year < 1582 || (date.year == 1582 && date.month < OKT) || (date.year == 1582 && date.month == OKT && date.day < 15)) {
         return 0;
     } else if (date.year > 9999) {
         return 0;
     } else {
         return 1;
     }
 }
// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
// BEGIN-STUDENTS-TO-ADD-CODE
 int is_valid_date(date_t date) {
     if (!is_gregorian_date(date)) {
         return 0;
     }

     if (get_month_length(date) == 0) {
         return 0;
     }

     if (date.day < 1 || date.day > get_month_length(date)) {
         return 0;
     }

     return 1;
 }
// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
// BEGIN-STUDENTS-TO-ADD-CODE
 weekday_t calculate_weekday(date_t date) {
     assert(is_valid_date(date));
     int m = 1 + (date.month + 9) % 12;
     int a = (date.month < MAR) ? date.year - 1 : date.year;
     int y = a % 100;
     int c = a / 100;

     int weekday = ((date.day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
     return (weekday_t)weekday;
 }
// END-STUDENTS-TO-ADD-CODE



/**
 * @brief   TASK2: print weekday as 3-letter abreviated English day name
 */
// BEGIN-STUDENTS-TO-ADD-CODE
 void print_weekday(weekday_t day) {
     assert(day >= SUN && day <= SAT);
     const char* weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
     printf("%s\n", weekdays[day]);
 }
// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[])
{
    // TASK1: parse the mandatory argument into a date_t variable and check if the date is valid
    // BEGIN-STUDENTS-TO-ADD-CODE
    if (argc < 2) return EXIT_FAILURE;
    int year, month, day;
    int res = sscanf(argv[1], "%d-%d-%d", &year, &month, &day);
    if (res != 3) return EXIT_FAILURE;
    date_t date = { year, month, day };
    if (!is_valid_date(date)) return EXIT_FAILURE;
    // END-STUDENTS-TO-ADD-CODE

    // TASK2: calculate the weekday and print it in this format: "%04d-%02d-%02d is a %s\n"
    // BEGIN-STUDENTS-TO-ADD-CODE
    weekday_t weekday = calculate_weekday(date);
    printf("%4d-%02d-%02d is a ", date.year, date.month, date.day);
    print_weekday(weekday);
    // END-STUDENTS-TO-ADD-CODE

    return EXIT_SUCCESS;
}

