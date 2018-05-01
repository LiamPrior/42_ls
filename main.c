/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:37:47 by lprior            #+#    #+#             */
/*   Updated: 2018/04/30 22:18:46 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info  *ft_ls(t_env *all, char *path, t_info *info)
{
    DIR             *type;
    struct dirent   *file;

    if ((type = opendir(path)) == NULL)// i need to make it so i can take in a file as a parameter. Maybe i can check in the node creation if its a file and if its not then report error.
        ft_error(1, path);
    while ((file = readdir(type)))
    {
        all->type = ft_strdup(path);
        all->type = ft_strjoin2(path, file->d_name);
        if ((ft_strncmp(file->d_name, ".", 1) == 0 && all->options.a == true)
            || (ft_strncmp(file->d_name, ".", 1) != 0))
                info = ft_create_node(all, info, all->type, file->d_name);//file);
        else
            continue;
        if (S_ISDIR(info->data->st_mode) && all->options.R == true 
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

void    ft_parse_paths(int argc, char **argv, t_env *all)
{
    all->i = 0;
    if (argv[all->x] && argv[all->x][all->i] != '-')
    {
        all->paths[all->px] = ft_strnew(ft_strlen(argv[all->x]) + 1);//+ 2
        while (all->i < ft_strlen(argv[all->x]))
        {
            all->paths[all->px][all->i] = argv[all->x][all->i];
            all->i++;
        }
        all->paths[all->px][all->i] = '\0';
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
                    ft_error(0, argv[all->x]);//i changed this
            all->i++;
        }
    }
    else
        return ;
    ft_toggle_options(argc, argv, all);
}

void ft_check_paths(t_env *all)
{
    DIR             *dir;
    struct stat     *info;

    all->px = 0;
    if (!(all->paths[all->px]))
    {
        all->paths[all->px] = ft_strnew(2);
        all->paths[all->px][all->px] = '.';
        return ;
    }
    else
        while (all->paths[all->px])
        {
            lstat(all->paths[all->px], info);//so right here you might now need to open it too check it!
            if (!(dir = opendir(all->paths[all->px])) S_ISDIR(info->st_mode) && !S_ISREG(info->st_mode) 
                && !S_ISCHR(info->st_mode) && !S_ISBLK(info->st_mode) 
                    && !S_ISFIFO(info->st_mode) && !S_ISLNK(info->st_mode)
                        && !S_ISSOCK(info->st_mode))
                            ft_error(1, all->paths[all->px]);
            else if (!(dir = opendir(all->paths[all->px])))//might be able to just check with marcros
                all->info = ft_create_node(all, all->info, all->paths[all->px], all->paths[all->px]);
        }
    while (all->info && all->info->prev != NULL)
        all->info = all->info->prev;
    all->px = 0;
    return ;
}
int     main(int argc, char **argv)//okay liam so whats happening is you are trying to take a file as an argument
{
    t_env all;

    ft_init(&all, argc);
    ft_toggle_options(argc, argv, &all);
    ft_parse_paths(argc, argv, &all);
    // all.px = 0;
    ft_check_paths(&all);
    // all.px = 0;
    // if (!(all.paths[all.px]))
    // {
    //     all.paths[all.px] = ft_strnew(2);
    //     all.paths[all.px][all.px] = '.';
    // }
    all.info = ft_ls(&all, all.paths[all.px], all.info);
    all.info = ft_init_merge(&all, all.info, 1);
    ft_display(&all, all.info);
    return (0);
}
