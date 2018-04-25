/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:37:47 by lprior            #+#    #+#             */
/*   Updated: 2018/04/24 21:46:36 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info  *ft_ls(t_env *all, char *path, t_info *info)
{
    DIR             *type;
    struct dirent   *file;
    struct stat     *data;

    if ((type = opendir(path)) == NULL)
        ft_error(1, path);
    while ((file = readdir(type)))
    {
        data = (struct stat *)malloc(sizeof(struct stat));
        all->type = ft_strdup(path);
        all->type = ft_strjoin2(path, file->d_name);
        if ((ft_strncmp(file->d_name, ".", 1) == 0 && all->options.a == true)
            || (ft_strncmp(file->d_name, ".", 1) != 0))
                info = ft_create_node(info, all->type, file);
        else
            continue;
        lstat(all->type, data);
        if (S_ISDIR(data->st_mode) && all->options.R == true 
            && ft_strncmp(file->d_name, ".", 1) != 0)
                info->sub = ft_ls(all, all->type, info->sub);
        else if (info)
            info->sub = NULL;
    }
    closedir(type);
    while (info && info->prev != NULL)
        info = info->prev;
    return (info);
}



void    ft_parse_paths(int argc, char **argv, t_env *all)//
{
    all->i = 0;
    if (argv[all->x] && argv[all->x][all->i] != '-')
    {
        all->paths[all->px] = ft_strnew(ft_strlen(argv[all->x]));
        while (all->i < ft_strlen(argv[all->x]))
        {
            all->paths[all->px][all->i] = argv[all->x][all->i];
            all->i++;
        }
        all->paths[all->px][all->i] = '/';
        all->paths[all->px][all->i + 1] = '\0';
    }
    else
        return ;
    all->x = all->x + 1;
    all->px = all->px + 1;
    ft_parse_paths(argc, argv, all);
}

void     ft_toggle_options(int argc, char **argv, t_env *all)
{
    all->i = 0;
    all->x = all->x + 1;
    if (argv[all->x] && argv[all->x][all->i] == '-' && argc > all->x)
    {
        all->i++;
        while (argv[all->x][all->i])
        {
            all->options.R = argv[all->x][all->i] == 'R' ? true : all->options.R;
            all->options.a = argv[all->x][all->i] == 'a' ? true : all->options.a;
            all->options.t = argv[all->x][all->i] == 't' ? true : all->options.t;
            all->options.l = argv[all->x][all->i] == 'l' ? true : all->options.l;
            all->options.r = argv[all->x][all->i] == 'r' ? true : all->options.r;
            if (argv[all->x][all->i] != 'R' && argv[all->x][all->i] != 'a' &&
                argv[all->x][all->i] != 't' && argv[all->x][all->i] != 'l' &&
                argv[all->x][all->i] != 'r' && argv[all->x][all->i])
                    ft_error(0, NULL);
            all->i++;
        }
    }
    else
        return ;
    ft_toggle_options(argc, argv, all);
}

int     main(int argc, char **argv)
{
    t_env all;
// printf("herebitch\n");
    ft_init(&all, argc);
    // printf("herebitch2\n");
    ft_toggle_options(argc, argv, &all);
    ft_parse_paths(argc, argv, &all);
    all.px = 0;
    if (!(all.paths[all.px]))
    {
        all.paths[all.px] = ft_strnew(2);
        all.paths[all.px][all.px] = '.';
        all.paths[all.px][all.px + 1] = '/';
    }
    // else// while (px < argc)
    all.info = ft_ls(&all, all.paths[all.px], all.info);
    // printf("GIVE A FUCK ABOUT NOTHING]\n");
    // while (temp)
    // {
    //     printf("%s\n", temp->path);
    //     temp = temp->next;
    // }
    // t_info *temp = all.info;
    // printf("[%s]\n", temp->next->next->next->next->next->next->sub->next->next->name);
    // printf("its valid [%s]\n", temp->sub->path);
    // printf("[%s]\n", all.info->next->name);
    all.info = ft_merge_sort(&all, all.info);
    // all.info = call_merge(&all, all.info);
    // t_info *temp = all.info;
    // while (temp)
    // {
    //     printf("%s\n", temp->path);
    //     temp = temp->next;
    // }
    // printf("[%s]\n", all.info->next->name);
    ft_display(&all, all.info);
    // printf("\n\nHERE\n\n");
    // ft_display();
    return (0);
}

// printf("asdfasdfasf %d\n", all.x);
// printf("R[%d]a[%d]t[%d]l[%d]r[%d]\n", all.options.R, all.options.a, all.options.t, all.options.l, all.options.r);

// int x = 0;
// while (all.paths[x])
// {
//     printf("path arg [%d][%s]\n", x, all.paths[x]);
//     x++;
// }0