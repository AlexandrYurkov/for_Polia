#include "../minishell.h"

void    ft_unset_next_step(t_envp **envp, char *name)
{
    t_envp  *tmp;

    tmp = *envp;
    tmp = search_name(tmp, name);
    if (!tmp)
    {
        printf("");
        return ;
    }
    delete_list(&tmp);
    *envp = struct_head(tmp);
}

void    ft_unset(t_envp **envp, char **name)
{
    int i;

    i = 0;
    while (name[++i])
        ft_unset_next_step(envp, name[i]);
    data.exit_status = 0;
}
