#include <stdio.h>

int main(void)
{
    for(int repetition = 0 ; repetition < 5 ; ++repetition)
    {
        for(int rampe = 0 ; rampe < 10 ; ++rampe)
        {
            printf("%d ", rampe);
        }

        puts("");
    }

    return 0;
}