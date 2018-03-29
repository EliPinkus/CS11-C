#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    char s[100];
    int i;
    int ran;

    srand(time(0));
    ran = (rand() % 10) + 1;
    printf("enter your name: ");
    scanf("%99s", s);
    printf("Hello , %s\n", s);

    for (i = 0; i < ran; i++)
    {
        if (ran % 2 == 0)
        {
            printf("<%d>: hello, %s!\n", ran, s);
        }
        else
        {
            printf("<%d>: hi there, %s!\n", ran, s);
        }
    }
    return 0;
}