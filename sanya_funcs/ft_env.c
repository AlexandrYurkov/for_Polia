#include "../minishell.h"

void    ft_env_next_step(t_envp *envp)
{
    t_envp  *tmp;

    tmp = envp;
    while (tmp)
    {
        if (tmp->value == NULL)
            tmp = tmp->next;
        else
        {
            printf("%s=%s\n", tmp->name, tmp->value);
                tmp = tmp->next;
        } 
    }   
}

void    ft_env(t_envp *envp, char **argv)
{
    int i;

    i = array_len(argv);
    if (i >= 1)
    {
        printf("env: ‘%s’: No such file or directory\n", argv[1]);
        data.exit_status = 127;
        return ;
    }
    else
        ft_env_next_step(envp);
}
