#include <stdio.h>

struct Haab_t
{
    int day;
    char month[8];
    char month_index;
    int year;
};

char *haab_month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac",
                      "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

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
    int i;
    char s[10];
    struct Haab_t haabcal;
    
    while(scanf("%d.%s", &haabcal.day, haabcal.month) != EOF)
    {
        printf("%d\n", lookup(haabcal.month));
    }

   
    
    return 0;
}
