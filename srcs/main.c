#include "computorv1.h"

void    final_init(t_final *final, int deg)
{
    int i = 0;
    while (i < deg + 1)
    {
        final[i].nb = 0;
        final[i].exp = i;
        i++;
    }
}

void    show_sct(t_struct* sct)
{
    while((sct))
    {
        printf("nb = %g, op = %c, exp = %d\n", sct->nb, sct->op, sct->exp);
        sct = sct->next;
    }
}

int main(int ac, char **av)
{
    char* str = NULL;
    if (ac > 2)
        return 1;
    else if (ac == 1)
    {
        str = readline("");
        (void)str;
    }
    else
        str = av[1];
    t_struct*   left = NULL;
    t_struct*   right = NULL;
    int deg = 0;
    if (parser(str, &left, &right, &deg) || deg < 0)
    {
        free_structs(&left, &right);
        return (1);
    }
    show_sct(left);
    show_sct(right);
    calc(left, right, deg);
    free_structs(&left, &right);
    return (0);
}