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
        printf("Bad format error\n");
        //fonction free a rajouter
        return (1);
    }
    // parser(str, &left, &right, &deg);
    calc(left, right, deg);
    return (0);
}