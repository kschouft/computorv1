#include "computorv1.h"

int fill_exponent(char *str, int *i, int *exp, int *deg)
{
    int nb = 0;
    if (str[*i] < '0' || str[*i] > '9')
        return 1;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        nb = nb * 10 + (str[*i] - '0');
        *i += 1;
    }
    *exp = nb;
    if (nb > *deg)
        *deg = nb;
    return 0;
}

int fill_number(char* str, int* i, double* nbr)
{
    double nb = 0;
    double divisor = 10;
    if (str[*i] < '0' || str[*i] > '9')
        return 1;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        nb = nb * 10 + (str[*i] - '0');
        *i += 1;
    }
    if (str[*i] == '.')
    {
        *i += 1;
        if (str[*i] < '0' || str[*i] > '9')
            return 1;
        while (str[*i] >= '0' && str[*i] <= '9')
        {
            nb += (str[*i] - '0') / divisor;
            divisor *= 10;
            *i += 1;
        }
    }
    *nbr = nb;
    return 0;
}

int fill_node(char* str, int* i, t_struct* curr, int* deg)
{
    curr->op = '+';
    if (str[*i] == '+' || str[*i] == '-')
    {
        curr->op = str[*i];
        *i += 1;
    }
    skip_spaces(str, i);
    if (fill_number(str, i, &curr->nb))
        return 1;
    skip_spaces(str, i);
    if (str[*i] != '*')
        return 1;
    *i += 1;
    skip_spaces(str, i);
    if (str[*i] != 'X')
        return 1;
    *i += 1;
    if (str[*i] != '^')
        return 1;
    *i += 1;
    if (fill_exponent(str, i, &curr->exp, deg))
        return 1;
    if (curr->op == '-')
        curr->nb = -curr->nb;
    return 0;    
}

int parser(char* src, t_struct** left, t_struct** right, int* deg)
{
    int i = 0;
    t_struct* head;
    t_struct** curr = left;
    bool equal_flag = false;
    while (src[i])
    {
        skip_spaces(src, &i);
        if (!src[i])
            break;
        if (src[i] == '=')
        {
            if (equal_flag || !(*curr))
                return 1;
            (*curr)->next = NULL;
            (*curr) = head;
            curr = right;
            equal_flag = true;
            i++;
        }
        else if ((src[i] >= '0' && src[i] <= '9') || src[i] == '+' || src[i] == '-')
        {
            if (*curr && src[i] >= '0' && src[i] <= '9')
                return 1;
            if (!(*curr))
            {
                (*curr) = malloc(sizeof(t_struct));
                if (!(*curr))
                    return 1;
                head = (*curr);
                (*curr)->prev = NULL;
                (*curr)->next = NULL;
            }
            else
            {
                (*curr)->next = malloc(sizeof(t_struct));
                if (!(*curr)->next)
                    return 1;
                (*curr)->next->prev = (*curr);
                (*curr) = (*curr)->next;
                (*curr)->next = NULL;
            }
            if (fill_node(src, &i, *curr, deg))
            {                
                (*curr)->next = NULL;
                (*curr) = head;
                return 1;
            }
        }
        else
        {
            if (*curr)
            {
                (*curr)->next = NULL;
                (*curr) = head;
            }
            return 1;
        }
    }
    if (!equal_flag || !(*curr))
        return 1;
    if (*curr)
    {
        (*curr)->next = NULL;
        (*curr) = head;
    }
    return 0;
}