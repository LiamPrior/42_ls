/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:37:47 by lprior            #+#    #+#             */
/*   Updated: 2018/04/21 23:30:27 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// DIR     *ft_type(t_env *all, DIR *type, char *path)
// {
//     struct stat     *data;

//     data = (struct stat *)malloc(sizeof(struct stat));
//     if (all->px == 0 && all->paths[all->px] == NULL)
//     {
//         all->paths[all->px] = ft_strnew(1);
//         all->paths[all->px][0] = '.';
//     }
//     if (all->paths[all->px] && path == NULL 
//         && (type = opendir(all->paths[all->px])) == NULL)
//             ft_error(1, all->paths[all->px]);
//     else if (path != NULL)
//     {
//         lstat(path, data);
//         if(S_ISDIR(data->st_mode) == 0)
//             type = opendir(all->paths[all->px]);
//         else if (S_ISDIR(data->st_mode) && (type = opendir(path)) == NULL)
//             ft_error(1, path);
//     }
//     free(data);
//     return (type);
// }

// t_info *ft_ls(t_env *all, t_info *info, char *path)//shit code that liam writes. obviously it doesnt work
// {
    // DIR             *type;
    // struct dirent   *file;
    // struct stat     *data;

//     // printf("[%s]\n", path);
//     // type = ft_type(all, type, path);
//     if ((type = opendir(path)) == NULL)
        
//     while ((file = readdir(type)) != NULL)
//     {
//         data = (struct stat *)malloc(sizeof(struct stat));
//         if (path == NULL)
//             path = ft_strdup(all->paths[all->px]);
//         path = ft_strjoin2(path, file->d_name);
//         info = ft_create_node(info, path, file);
//         data->st_mode = 0;
//         lstat(path, data);
        // if (S_ISDIR(data->st_mode) && all->options.R == true 
        //     && ft_strncmp(file->d_name, ".", 1) != 0)
//                 // && (all->paths[all->px] = path))
//                     info->sub = ft_ls(all, info->sub, path);//all->paths[all->px]);
//         else
//             info->sub = NULL;
//         path = all->paths[all->px];
//     }
    // closedir(type);
    // while (info->prev != NULL)
    //     info = info->prev;
    // return (info);
// }

t_info  *ft_ls(t_env *all, char *path, t_info *info)
{
    DIR             *type;
    struct dirent   *file;
    struct stat     *data;

    // printf("[%s]\n", path);
    if ((type = opendir(path)) == NULL)
        ft_error(1, path);
    while ((file = readdir(type)))
    {
        data = (struct stat *)malloc(sizeof(struct stat));
        all->dir = ft_strdup(path);
        all->dir = ft_strjoin2(path, file->d_name);
        info = ft_create_node(info, all->dir, file);
        lstat(all->dir, data);
        if (S_ISDIR(data->st_mode) && all->options.R == true 
            && ft_strncmp(file->d_name, ".", 1) != 0)
                info->sub = ft_ls(all, all->dir, info->sub);
        else
            info->sub = NULL;
    }
    closedir(type);
    while (info->prev != NULL)
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

    ft_init(&all, argc);
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
    ft_ls(&all, all.paths[all.px], all.info);
    return (0);
}

// printf("asdfasdfasf %d\n", all.x);
// printf("R[%d]a[%d]t[%d]l[%d]r[%d]\n", all.options.R, all.options.a, all.options.t, all.options.l, all.options.r);

// int x = 0;
// while (all.paths[x])
// {
//     printf("path arg [%d][%s]\n", x, all.paths[x]);
//     x++;
// }