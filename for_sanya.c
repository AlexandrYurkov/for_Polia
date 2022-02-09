#include "minishell.h"

t_envp *init_t_envp(t_data *data, t_envp *envp) // инцилизация t_envp
{
    int i = 0;
    char **tmp;
   
    while (data->env[i])
    {
        tmp = ft_strsplit(data->env[i], '=');
        if (envp == NULL)
            envp = ft_lstnew(tmp[0], tmp[1]);
        else
            push_back(tmp[0], tmp[1], envp);
           free(tmp);
        i++;
    }
    return (envp);
}

int env_copy(t_data *data, char **env)
{
    int i;
    int j;

    i = 0;
    j = -1;
    while (env[i] != NULL)
        i++;
    data->env = (char **)malloc(sizeof(char *) * (i + 1));
    if (!data->env)
        return (1);
    while (env[++j] != NULL)
    {
        data->env[j] = strdup(env[j]);
        if (!data->env[j])
            return (1);
    }
    data->env[j] = NULL;
    return (0);
}

int main(int argc, char **argv, char **env) // test
{
    t_data *data;
    t_envp *envp;
   
    (void)argc;
    (void)argv;

    data = malloc(sizeof(t_data));

    char *check = ft_strdup("CHECK");

    envp = NULL; 
    if (!data)
        exit(1);
    if (env_copy(data, env) == 1)
        return (1);
    envp = init_t_envp(data, envp);
    if (!envp)
        exit(2);
    ft_export(envp, check);
    printf("_______________________\n");
    // ft_export(envp, NULL);
    // printf("_______________________\n");
    ft_env(envp);
    envp = struct_head(envp); 
    free_env(data);
    free(data);
    free(check);
    ft_lstclear(&envp);
    return (0);

}