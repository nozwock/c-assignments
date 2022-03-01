#include <stdbool.h>
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

bool is_date_equal(const struct Date d1, const struct Date d2);

int main(void)
{
    struct Date date[2];
    int num_dates = sizeof(date) / sizeof(*date);
    for (int i = 0; i < num_dates; i++) {
        printf("enter %dth date (dd/mm/yyyy): ", i + 1);
        scanf("%d%d%d", &date[i].day, &date[i].month, &date[i].year);
    }

    if (is_date_equal(date[0], date[1])) {
        printf("dates are equal\n");
    } else {
        printf("dates are unequal\n");
    }
}

bool is_date_equal(const struct Date d1, const struct Date d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) {
        return true;
    }
    return false;
}