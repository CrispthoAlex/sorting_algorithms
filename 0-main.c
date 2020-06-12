#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int array1[] = {19}; /*int array2 = NULL;*/
    int array3[] = {5,4};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t n1 = 1, n2 = 5, n3 = 2;

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);

    printf("----------------------------\n");

    print_array(array1, n1);
    printf("\n");
    bubble_sort(array1, n1);
    printf("\n");
    print_array(array1, n1);


    printf("----------------------------\n");

    print_array(NULL, n2);
    printf("\n");
    bubble_sort(NULL, n2);
    printf("\n");
    print_array(NULL, n2);

    printf("----------------------------\n");

    print_array(array3, n3);
    printf("\n");
    bubble_sort(array3, n3);
    printf("\n");
    print_array(array3, n3);

    return (0);
}
