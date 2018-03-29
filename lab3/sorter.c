#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_LEN 32

void minSort(int len, int array[]);
void bubbleSort(int len, int array[]);

int main(int argc, char *argv[])
{
    int len;
    int nums[MAX_LEN];
    int b;
    int q;
    int i;

    /* print usage if no args */

    if (argc == 0)
    {
        fprintf(stderr, "1: usage: %s [-b] [-q] [num1 num2... \
            (max 32 numbers)", argv[0]);
        exit(1);
    }

    len = 0;
    b = 0;
    q = 0;

    /* go through command line args */
    for (i = 1; i < argc; i++)
    {
        /* check if arg -b */
        if (strcmp(argv[i], "-b")==0)
        {
            b = 1;
        }
        /* check if arg -q */
        else if (strcmp(argv[i], "-q")==0)
        {
            q = 1;
        }
        /* store int */
        else
        {

            if (len >= MAX_LEN)
            {
                fprintf(stderr, "2: usage: %s [-b] [-q] [num1 num2... \
                    (max 32 numbers)", argv[0]);
                exit(1);
            }
            nums[len] = atoi(argv[i]);
            len++;
        }

    }
    


    /* if no nums print usage */
    if (len == 0)
    {
        fprintf(stderr, "3: usage: %s [-b] [-q] [num1 num2... \
                    (max 32 numbers)", argv[0]);
        exit(1);
    }

    if (b == 1)
    {
        bubbleSort(len, nums);
    }
    else
    {
        minSort(len, nums);
    }

    if (q != 1)
    {
        for (i = 0; i < len; i++)
        {
           printf("%d\n", nums[i]);
        }
    }
    

    return 0;
}

/* sorts via minSort
takes as arguments the length of an array and an array
mutates the array such that it is sorted and returns void

 */
void minSort(int len, int array[])
{
    int start;
    int smallest;
    int t1;
    int t2;
    int i;

    for (start = 0; start < len - 1; start++)
    {
        smallest = start;
        for (i = start + 1;i < len; i++)
        {
            if (array[i] < array[smallest])
            {
                smallest = i;
            }
        }
        t1 = array[start];
        t2 = array[smallest];

        array[smallest] = t1;
        array[start] = t2;
    }
    for(i=1; i < len; i++)
    {
        assert(array[i] >= array[i-1]);
    }
}

/* sorts via bubble sort 
takes as arguments the length of an array and an array
mutates the array such that it is sorted and returns void
*/
void bubbleSort(int len, int array[])
{
    int temp;
    int i;
    int swapped;
    swapped = 1;

    while (swapped == 1)
    {
        swapped = 0;

        for (i = 1; i < len; i++)
        {
            if (array[i] < array[i-1])
            {
                temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swapped = 1;
            }
        }
    }

    

    for(i = 1; i < len; i++)
    {
        assert(array[i] >= array[i-1]);
    }
}