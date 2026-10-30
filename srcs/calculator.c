#include "computorv1.h"

void complexe(t_final* final)
{
    printf("%g/%g + %gi/%g\n", -final[0].nb, final[2].nb, final[1].nb, final[2].nb);
    printf("%g/%g - %gi/%g\n", -final[0].nb, final[2].nb, final[1].nb, final[2].nb);
}

void discriminant(t_final* final)
{
    double res;
    res = ((final[1].nb *  final[1].nb) - (4 * final[2].nb * final[0].nb));
    if (res > 0)
    {
        printf ("Discriminant is strictly positive, the two solutions are:\n");
        printf ("%g\n", ((-(final[1].nb)) - ft_sqrt(res)) / (2 * final[2].nb));
        printf ("%g\n", ((-(final[1].nb)) + ft_sqrt(res)) / (2 * final[2].nb));
    }
    else if (res == 0)
    {
        printf("Discriminant is null, the solution is:\n");
        printf ("%g\n", (-(final[1].nb) / (2 * final[2].nb)));
    }
    else
    {
        printf("Discriminant is strictly negative, the two complex solutions are:\n");
        complexe(final);
    }
}

int reduc_deg(t_final* final, int deg)
{
    int i = 0;
    int lvl = 0;
    while (i <= deg)
    {
        if (final[i].nb != '0')
            lvl++;
        i++;
    }
    return deg;
}

void solution(t_final* final, int deg)
{
    int lvl = reduc_deg(final, deg);
    if (lvl == 0)
    {
        if (final[0].nb != 0)
            printf("No solution\n");
        else
            printf("Any real number is a solution.\n");
    }
    else if (lvl == 1)
    {
        printf("The solution is:\n");
        printf("%g\n", -(final[0].nb / final[1].nb));
    }
    else if (lvl == 2)
        discriminant(final);
    else
        printf("The polynomial degree is strictly greater than 2, I can't solve.\n");
}

void    reduc_form(t_final* final, int deg)
{
    int i = 0;
    double tmp = 0;
    bool flag = false;
    printf("Reduced form: ");
    while (i <= deg)
    {
        if (flag == false)
        {
            if (final[i].nb < 0)
                tmp -= final[i].nb;
            printf("%g * X^%d", final[i].nb, final[i].exp);
            flag = true;
            tmp = 0;
        }
        else
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
        i++;
    }
    printf(" = 0\n");
    if (deg != 0)
        printf("Polynomial degree : %d\n", deg);
    solution(final, deg);
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
