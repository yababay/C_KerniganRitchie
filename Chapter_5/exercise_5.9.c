#include <stdio.h>

static char daytab[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day); 
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int d, m;

    printf("%d\t%d\t%d\t%d\t%d\t%d\n", day_of_year(1991, 7, 16),
            day_of_year(0, 10, 17),
            day_of_year(1670, -4, 17),
            day_of_year(2028, 17, 3),
            day_of_year(1999, 3, -8),
            day_of_year(1813, 2, 29));

    month_day(2022, 256, &m, &d);
    printf("%d\t%d\n", m, d);

    month_day(0, 256, &m, &d);
    printf("%d\t%d\n", m, d);

    month_day(1954, -4, &m, &d);
    printf("%d\t%d\n", m, d);

    month_day(1900, 366, &m, &d);
    printf("%d\t%d\n", m, d);

    month_day(2000, 367, &m, &d);
    printf("%d\t%d\n", m, d);

    return 0;
}

int day_of_year(int year, int month, int day) {
    int i, leap;

    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return -1;
    }
    
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    if (day > *(*(daytab+leap)+month)) {
        return -1;
    }

    for (i = 1; i < month; i++) {
        day += *(*(daytab+leap)+i);
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    if (year < 1 || yearday < 1 || yearday > 365+leap) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > *(*(daytab+leap)+i); i++) {
        yearday -= *(*(daytab+leap)+i);
    }
    *pmonth = i;
    *pday = yearday;
}
