#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct s_struct
{
    char        op;
    double      nb;
    int         exp;
    struct s_struct  *prev;
    struct s_struct  *next;
}               t_struct;