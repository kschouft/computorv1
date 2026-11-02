#include "computorv1.h"

int   ft_strlen(const char* str)
{
    int i = 0;
    while(str[i])
        ++i;
    return i;
}

void skip_spaces(char* str, int* i)
{
    while (str[*i] == ' ')
        *i += 1;    
}

double ft_sqrt(double nb)
{
    double x;
    double prev;
    int i;

    if (nb < 0)
        return -1;
    if (nb == 0)
        return 0; 
    x = nb >= 1.0 ? nb : 1.0;
    i = 0;
    while (i < 50)
    {
        prev = x;
        x = (x + nb / x) / 2.0;
        if (x == prev)
            break;
        i++;
    }
    return x;
}

int ft_abs(int nb)
{
    if (nb >= 0)
        return nb;
    else
        return (-nb);
}

double ft_fabs(double nb)
{
    if (nb >= 0)
        return nb;
    else
        return (-nb);    
}

void free_structs(t_struct** left, t_struct** right)
{
    t_struct* curr;
    while (*left)
    {
        curr = (*left);
        *left = (*left)->next;
        free(curr);
        curr = NULL;
    }
    while (*right)
    {
        curr = (*right);
        *right = (*right)->next;
        free(curr);
        curr = NULL;
    }
}