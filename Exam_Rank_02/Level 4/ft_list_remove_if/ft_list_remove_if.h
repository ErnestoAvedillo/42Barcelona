#ifndef FT_LIST_REMOVE_IF_H
# define FT_LIST_REMOVE_IF_H
#include<stdlib.h>
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
#endif