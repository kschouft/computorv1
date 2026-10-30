#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_struct
{
    char        op;
    double      nb;
    int         exp;
    struct s_struct  *prev;
    struct s_struct  *next;
}               t_struct;

typedef struct s_final
{
    double      nb;
    int         exp;   
}               t_final;

//debug
void    show_struct(t_struct *left, t_struct *right);

//main
void    final_init(t_final *final, int deg);
void    discriminant(t_final* final);
void    reduc_form(t_final* final, int deg);
int     reduc_deg(t_final* final, int deg);
void    solution(t_final* final, int deg);
void    calc(t_struct *left, t_struct *right, int deg);
int     main(int ac, char **av);

//parsing
int     fill_exponent(char *str, int *i, int *exp, int* deg);
int     fill_number(char* str, int* i, double* nbr);
int     fill_node(char* str, int* i, t_struct* curr, int* deg);
int     parser(char* src, t_struct** left, t_struct** right, int* deg);

//utils
int     get_degree(char* str);
int     ft_strlen(const char* str);
void    skip_spaces(char* str, int* i);
double  ft_sqrt(double nb);
int     ft_abs(int nb);
double  ft_fabs(double nb);