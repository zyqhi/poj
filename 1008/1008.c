/*
 * Author	: Yuqang Zhou
 * Date		: 
 * Purpose	:
 * Discription  :
 */

#include <stdio.h>
#include <string.h>

struct Haab_t
{
    int day;
    char month[8];
    char month_index;
    int year;
};

struct Tzolkin_t
{
    int day_num;
    char day_index;
    int year;
};

char *haab_month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac",
                      "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char *tzolkin_day[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",
                       "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int lookup(char *value)
{
    int key;
    for (key = 0; key < 19; key++)
    {
        if (strcmp(haab_month[key], value) == 0)
            return key;
    }
    return -1; //not found
}

int main(int argc, char *argv[])
{
    int i, n;
    int days;
    int flag = 1;
    
    struct Haab_t haabcal;
    struct Tzolkin_t tzolkincal;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d.%s%d", &haabcal.day, haabcal.month, &haabcal.year);
        //printf("%d\t%s\t%d\n", haabcal.day, haabcal.month, haabcal.year);
        haabcal.month_index = lookup(haabcal.month);
        days = 365*haabcal.year + 20*haabcal.month_index + haabcal.day + 1;

        tzolkincal.year = days/260;
        days = days%260;
        if (days == 0)
        {
            tzolkincal.day_num = 13;
            tzolkincal.day_index = 19;
        }

        tzolkincal.day_num = (days%13 == 0) ? 13 : (days%13);
        tzolkincal.day_index = (days%20 == 0) ? 20 : (days%20);
        if (flag)
        {
            printf("%d\n", n);
            flag = 0;
        }

        printf("%d %s %d\n", tzolkincal.day_num, tzolkin_day[tzolkincal.day_index-1], tzolkincal.year);
    }

    return 0;
}


