/* performs the quicksort algorithm on a linked list data structure */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "memcheck.h"



node * quickSort(node *list)
{

    node *greater_nums = NULL;
    node *lesser_nums = NULL;
    node *sorted_greater_nums = NULL;
    node *sorted_lesser_nums = NULL;
    node *helper = NULL;
    node *i = NULL;
    node *result = NULL;
    node *temp = NULL;

    /* check if list is empty or singleton */
    if (list == NULL || list->next == NULL)
    {
        return copy_list(list);
    }


    helper = create_node(list->data, helper);
    list = list->next;

    for (i = list; i != NULL; i = i->next) /* iterate through list */
    {
        if (i->data < helper->data)
        {
            lesser_nums = create_node(i->data, lesser_nums);
        }
        else
        {
            greater_nums = create_node(i->data, greater_nums);
        }
    }

    sorted_lesser_nums = quickSort(lesser_nums);
    sorted_greater_nums = quickSort(greater_nums);

    temp = append_lists(helper, sorted_greater_nums);
    result = append_lists(sorted_lesser_nums, temp);

    assert(is_sorted(result));

    free_list(temp);
    free_list(helper);
    free_list(greater_nums);
    free_list(lesser_nums);
    free_list(sorted_lesser_nums);
    free_list(sorted_greater_nums);
    free_list(i);
    return result;
}



int main (int argc, char *argv[])
{
    int i;
    int q;
    int count;

    node *list;
    node *result;

    list = NULL;
    count = 0;
    q = 0;


    /* read from command line */
    for (i=1; i < argc; i++)
    {
        /* check for output supression */
        if (strcmp(argv[i], "-q") == 0)
        {
            q = 1;
        }
        else
        {
            list = create_node(atoi(argv[i]), list);
            count++;
        }
    }

    /* check for no args and print usage statement */
    if (count == 0)
    {
        fprintf(stderr, "%s [-q] num1 num2 ...\n", argv[0]);
    }


    result = quickSort(list);
    free_list(list);
    if (q == 0)
    {
        print_list(result);
    }
    else
    {
        return 0;
    }
    free_list(result);
    print_memory_leaks();
    return 0;

}



