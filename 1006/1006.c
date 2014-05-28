/*
 * Author	: Yuqang Zhou
 * Date		: 
 * Purpose	:
 * Discription  :
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int p, e, i, d;
    int count = 0, days;
    int max = 21252;
    
    while (1)
    {
        count++;
        scanf("%d%d%d%d", &p, &e, &i, &d);

        if ((-1 == p) && (-1 == e) && (-1 == i) && (-1 == d))
            return 0;
        
        days = ((5544*p + 14421*e + 1288*i)%max - d + max)%max;
        
        if (days == 0)
        { 
            days = max; 
        }
        
        printf("Case %d: the next triple peak occurs in %d days.\n", count, days);
    }

    return 0;
}
