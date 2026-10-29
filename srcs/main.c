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

void discriminant(t_final* final)
{
    double res;
    res = ((final[1].nb *  final[1].nb) - (4 * final[2].nb * final[0].nb));
    if (res > 0)
    {
        printf ("Discriminant is strictly positive, the two solutions are:\n");
        printf ("%f\n", ((-(final[1].nb)) - ft_sqrt(res)) / (2 * final[2].nb));
        printf ("%f\n", ((-(final[1].nb)) + ft_sqrt(res)) / (2 * final[2].nb));
    }
}

void solution(t_final* final)
{
    printf("The solution is:\n");
    printf("%g\n", -(final[0].nb / final[1].nb));
}

void    reduc_form(t_final* final, int deg)
{
    int i = 0;
    double tmp = 0;
    bool flag = false;
    printf("Reduced form: ");
    while (i < 3)
    {
        if (final[i].nb != 0)
        {
            if (flag == false && final[i].nb != 0)
            {
                if (final[i].nb < 0)
                    tmp -= final[i].nb;
                printf("%g * X^%d", final[i].nb, final[i].exp);
                flag = true;
                tmp = 0;
            }
            else if (final[i].nb != 0)
            {
                if (final[i].nb < 0)
                {
                    tmp -= final[i].nb;
                    printf(" - ");
                }
                else
                {
                    tmp = final[i].nb;
                    printf(" + ");
                }
                printf("%g * X^%d", tmp, final[i].exp);
                tmp = 0;
            }
        }
        i++;
    }
    printf(" = 0\n");
    printf("Polynomial degree : %d\n", deg);
    if (deg == 2)
        discriminant(final);
    else if (deg == 1)
        solution(final);
    else
        printf("The polynomial degree is strictly greater than 2, I can't solve.\n");
}

void    calc(t_struct *left, t_struct *right, int deg)
{
    t_final *final = malloc(sizeof(t_final) * (deg + 1));
    int pos = 0;

    final_init(final, deg);

    while (left)
    {
        pos = left->exp;
        final[pos].nb += left->nb;
        left = left->next;
    }
    while (right)
    {
        pos = right->exp;
        final[pos].nb -= right->nb;
        right = right->next;
    }
    reduc_form(final, deg);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 1;
    t_struct*   left = NULL;
    t_struct*   right = NULL;
    int deg = 0;
    parser(av[1], &left, &right, &deg);
    if (deg <= 0)
    {
        printf("Bad format error\n");
        //fonction free a rajouter
        return (1);
    }
    calc(left, right, deg);
    return (0);
}