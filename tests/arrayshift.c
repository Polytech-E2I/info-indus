#include <stdio.h>

char ARRAY[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int SIZE = sizeof(ARRAY) / sizeof(ARRAY[0]) - 1;

int next_index(int i)
{
    if(i >= (SIZE-1))   return 0;
    else                return i+1;
}
int previous_index(int i)
{
    if(i <= 0)  return SIZE - 1;
    else        return i-1;
}

void forward_array(void)
{
    char temp = ARRAY[SIZE-1];

    for(int i = SIZE-1 ; i > 0 ; --i)
    {
        ARRAY[i] = ARRAY[i-1];
    }

    ARRAY[0] = temp;
}

int main(void)
{
    printf("%s\n", ARRAY);

    for(int i = 0 ; i < SIZE ; ++i)
    {
        forward_array();
        printf("%s\n", ARRAY);
    }

    return 0;
}