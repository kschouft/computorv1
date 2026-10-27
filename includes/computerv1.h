#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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