#include <stdio.h>
int calculate_Easter_date(int year);

/* this function computes the day of easter */
int main (void)
{
    int date;
    int year;

    while (scanf("%d", &year) != EOF)
    {
        date = calculate_Easter_date(year);
        /* check for year in range */
        if (date == 0)
        {
            fprintf(stderr, "Error: year given out of range \n");
        }
        /* check for date in march */
        else if (date < 0)
        {
            date = -1 * date;
            fprintf(stdout, "%d - March %d\n", year, date);
        }
        else
        /* otherwise the date is in april */
        {
            fprintf(stdout, "%d - April %d\n", year, date);
        }
    }

    return 0;
}


int calculate_Easter_date (int year)
{

    int goldNum;
    int currentCentury;
    int leapYears;
    int moonCorrection;
    int sunday;
    int epact;
    int fullMoonDateMarch;
    int easter;

    /* check for valid year */
    if (year > 39999 || year < 1582)
    {
        return 0;
    }

    /* find place in metonic cycle */
    goldNum = (year % 19) + 1;
    currentCentury = (year / 100) + 1;

    /* find skipped leap years */
    leapYears = 3 * currentCentury / 4 - 12;

    /* calculate the moon correction factor */
    moonCorrection = ((8 * currentCentury + 5) / 25) -5;

    /* helper for finding sunday in march */
    sunday = ((5 * year) / 4) - leapYears -10;

    /* get epact */
    epact = ((11 * goldNum) + 20 + moonCorrection - leapYears) % 30;


    if ((epact == 25 && goldNum > 11) || epact == 24)
    {
        epact ++;
    }

    /* get march full moon date */
    fullMoonDateMarch = 44 - epact;

    if (fullMoonDateMarch < 21)
    {
        fullMoonDateMarch += 30;
    }

    /* take the sunday after a full moon */
    easter = fullMoonDateMarch + 7 - (sunday + fullMoonDateMarch) % 7;

    if (easter > 31) /* date is in april */
    {
        easter -= 31;
    }
    else /* negative signals date in march */
    {
        easter -= 2 * easter;
    }

    return easter;

}