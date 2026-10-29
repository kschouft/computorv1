#include "computorv1.h"

void show_struct(t_struct *left, t_struct *right)
{
    printf("left\n");
    while (left)
    {
        printf("%f\n", left->nb);
        left = left->next;
    }
    printf("right\n");
    while (right)
    {
        printf("%f\n", right->nb);
        right = right->next;
    }   
}