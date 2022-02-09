#include "minishell.h"

t_envp *ft_lstnew(char *name, char *value) 
{
	t_envp *check;

	if (!(check = (t_envp *)malloc(sizeof(t_envp))))
		return (NULL);
	check->value = value;
    check->name = name;
	check->prev = NULL;
	check->next = NULL;
	return (check);
}

void push_back(char *name, char *value, t_envp *check)
{
	t_envp *next_node;

	if (!(next_node = (t_envp *)malloc(sizeof(t_envp))))
		exit (2);
	while (check->next)
    {
        check = check->next;
    }
	next_node->value = value;
    next_node->name = name;
	next_node->prev = check;
	next_node->next = NULL;
	check->next = next_node;
}
