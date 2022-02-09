#include "minishell.h"

t_envp *search_name(t_envp *envp, char *name) // функция поиска по структуре envp
{
    t_envp *tmp_head;
    int i;

    tmp_head = envp;
    i = -1;
    while (tmp_head != NULL)
    {
        i = ft_strcmp(name, tmp_head->name);
        if (i == 0)            
            break;
        tmp_head = tmp_head->next;
    }
    return (tmp_head); // обработать на NULL
}

t_envp *struct_head (t_envp *envp) //вспомогательная фун-ия для поиска головы
{
    t_envp *tmp;

    tmp = envp;
    while(tmp->prev)
        tmp = tmp->prev;
    envp = tmp;
    return (envp);
}



