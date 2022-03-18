#include "../minishell.h"

t_envp  *export_new_name(t_envp *envp, char *name)
{
    char    **tmp;
    int     check;
    int     i;

    i = 0;
    tmp = (char **)malloc(sizeof(char *) * 2);
    check = ft_strchr(name, '=');
    if (check == 0)
    {
        tmp[0] = ft_strdup(name);
        tmp[1] = NULL;
    }
    else
    {
        free(tmp);
        tmp = ft_split(name, '=');
    }
    if (!tmp)
        exit(2);
    push_back(tmp[0], tmp[1], envp);
    envp = struct_head(envp);
    free(tmp);
    return (envp);
}

t_envp  *copy_envp(t_envp *envp, t_envp *sort)
{
    t_envp  *tmp;
    char    *name;
    char    *value;

    tmp = envp;
    sort = NULL;
    while (tmp)
    {
        name = ft_strdup(tmp->name);
        if (tmp->value == NULL)
            value = NULL;
        else
            value = ft_strdup(tmp->value);
        if (!sort)
            sort = ft_lstnew(name, value);
        else
            push_back(name, value, sort);
        tmp = tmp->next;
    }
    sort = struct_head(sort);
    return (sort);
}

int change_envp(t_envp *envp, char *str)
{
    int     i;
    int     j;
    char    *name;
    char    *value;

    i = 0;
    j = 0;
    name = NULL;
    value = NULL;
    while (str[i])
    {
        if (str[i] == '=')
        {
            name = ft_substr(str, 0, i);
            j = i;
            break;
        }
        i++;
    }
    if (name == NULL)
        return (0);
    if (search_name(envp, name))
    {
        while (str[i])
            i++;
        value = ft_substr(str, j + 1, i - j);
        change_envp_value(envp, name, value);
        data.exit_status = 0;
        free(name);
        if (value)
            free(value);
        return (1);
    }
    free(name);
    if (value)
        free(value);
    return (0);
}

void    ft_export_next_step(t_envp **envp, char *name)
{
    t_envp  *sort;

    if (name != NULL)
    {
        if (change_envp(*envp, name))
            return ;
        *envp = export_new_name(*envp, name);
        return ;
    }
    sort = copy_envp(*envp, sort);
    swap_list(sort);
    sort = struct_head(sort);
    ft_lstclear(&sort);
    data.exit_status = 0;
}

void    ft_export(t_envp **envp, char **argv)
{
    int i;
    int j;

    i = 0;
    j = array_len(argv);
    if (argv[1] == NULL)
    {
        ft_export_next_step(envp, NULL);
        return ;
    }
    while (argv[i])
    {
        if (ft_isdigit_char(argv[i][0]))
        {
            printf("minishell: export: `%s': not a valid identifier\n", argv[i]);
            data.exit_status = 1;
            return ;
        }
        i++;
    }
    i = 1;
    while (argv[i])
    {
        ft_export_next_step(envp, argv[i]);
        i++;
    }
    return ;
}
