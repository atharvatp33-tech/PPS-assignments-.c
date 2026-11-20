#include <stdio.h>

int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1 && isLeap(year))
        return 29;
    return days[month];
}

/* Returns day of week for 1st of given month: 0 = Sunday, ..., 6 = Saturday */
int startDay(int month, int year) {
    int d = 1, y = year, m = month + 1;   /* m: 1..12 */
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3)
        y -= 1;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {
    const char *monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int year, month, day, start, days;

    printf("Enter year: ");
    scanf("%d", &year);

    if (year < 1) {
        printf("Invalid year.\n");
        return 1;
    }

    printf("\n========== CALENDAR FOR %d ==========\n", year);

    for (month = 0; month < 12; month++) {
        days = daysInMonth(month, year);
        start = startDay(month, year);

        printf("\n------------ %s ------------\n", monthNames[month]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        /* Print blank spaces before the 1st day */
        for (day = 0; day < start; day++)
            printf("     ");

        /* Print the days */
        for (day = 1; day <= days; day++) {
            printf("%5d", day);
            if ((day + start) % 7 == 0)
                printf("\n");
        }
        printf("\n");
    }

    return 0;
}
