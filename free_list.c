#include "minishell.h"

void	ft_lstclear(t_envp **lst) // очищение t_envp
{
	if (!lst || !(*lst))
		return ;
		ft_lstclear(&(*lst)->next);
		free((*lst)->name);
		free((*lst)->value);
		free(*lst);
	*lst = NULL;
}

void free_env(t_data *data) // очищение t_data
{
    int i;

    i = 0;
    while (data->env[i])
        free(data->env[i++]);
    free(data->env);
}
