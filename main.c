/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:37:47 by lprior            #+#    #+#             */
/*   Updated: 2018/04/19 23:25:58 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


t_info *ft_ls(t_env *all, t_info *info, char *path)
{
    DIR             *type;
    struct dirent   *file;
    struct stat     data;

    type = ft_type(type);
    while ((file = readdir(type)) != NULL)
    {
        if (path == NULL)
            path = ft_strdup(all->paths[all->px]);
        path = ft_strjoin2(path, file->d_name);
        info = ft_create_node(info, path, file);
        lstat(path, &data);
        if (S_ISDIR(data.st_mode) && all->options.R == true)
            info->sub = ft_ls(all, info->sub, info->path);
        else
            info->sub = NULL;
    }
    closedir(type);
    while (info->prev != NULL)
        info = info->prev;
    return (info);
}

DIR     *ft_type(t_env *all, DIR *type, char *path)
{
    struct stat     data;

    if (all->px == 0 && all->paths[all->px] == NULL)
    {
        all->paths[all->px] = ft_strnew(1);
        all->paths[all->px][0] = '.';
    }
    if (all->paths[all->px] && all->run == true)
    {
        if ((type = opendir(all->paths[all->px])) == NULL)//remembere files for 1
            ft_error(1, all->paths[all->px]);
        all->run = false;
    }
    else
    {
        lstat(path, &data);
        if (S_ISDIR(data.st_mode) && (type = opendir(path)) == NULL)//make sure that path is correct!!
            ft_error(1, path);
    }
    return (type);
}



// t_info   *ft_ls(t_env *all, t_info *info, char *path)//okay liam so for today the problem is strjoin2. its adding all files and dirs to the path and making the nodes incorrectly!
// {
    // DIR             *type;
    // struct dirent   *file;
    // struct stat     data;
//     char            *path2;

//     type = ft_type(all, type, path);
//     while ((file = readdir(type)) != NULL)
//     {
//         // printf("segfault3\n");
//         // printf("file->d_name = [%s] path = [%s]\n", file->d_name, path);
//         // sleep(1);
//         if (path == NULL)
//         {
//             path2 = ft_strnew(ft_strlen(all->paths[all->px]));
//             ft_strcpy(path2, all->paths[all->px]);
//             path2 = ft_strjoin2(path2, file->d_name);
//         }
//         else
//         {
//             // if (ft_strcmp(file->d_name, "..") != 0 && ft_strcmp(file->d_name, ".") != 0)
//             path = ft_strjoin2(path, file->d_name);
//             // free(path);
//             printf("NAME BABAY2 = [%s] FILE NAME = [%s]\n", path, file->d_name);
//             // sleep(2);
//         }
//         if (path == NULL)
//         {
//             info = ft_create_node(info, path2, file);
//             lstat(path2, &data);
//         }
//         else
//         {
//             info = ft_create_node(info, path, file);
//             lstat(path, &data);
//         }
//         // free(path);
//         if (S_ISDIR(data.st_mode) && all->options.R == true && ft_strcmp(file->d_name, "..") != 0 && ft_strcmp(file->d_name, ".") != 0)//
//         {
//             // printf("RECURSE path = %s name = %s\n", info->path, info->name);
//              all->info->sub = ft_ls(all, info->sub, info->path);
//         }
//         else
//             info->sub = NULL;
//         // free(path);
//     }
    // closedir(type);
    // while (info->prev != NULL)
    //     info = info->prev;
    // return (info);
// }

// void    ft_ls(t_env *all, t_info *list)//i need to free path every time
// {
//     DIR         *type;
//     struct dirent    *file;
//     struct stat       data;
//     char            path;

//     if (all->px == 0 && all->paths[all->px] == NULL)
//     {
//         all->paths[all->px] = ft_strnew(1);
//         all->paths[all->px][0] = '.';
//     }
//     if (all->paths[all->px])
//         if (type = opendir(all->paths[all->px]) == NULL)
//             ft_error(1, all);
//     while (file = readdir(type) != NULL)
//     {
//         path = ft_strnew(ft_strlen(all->paths[xp]));
//         ft_strcpy(path, all->paths[xp]);
//         ft_strjoin2(path, file->d_name);
//         list = ft_create_node(all, path, file);
// //i need to store info from the path into data.
//         lstat(path, &data);
//         if (S_ISDIR(data.st_mode) && all->options.R == true)//so if its a dir i need to recurse and create a new 
//             all->info->sub = ft_ls(all, list->sub);
//         // if (all->options.R == true && S_ISDIR(file))
            
        


//     }
                          
//     ft_ls(all); //recurse here for px
// }

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
    all.info = ft_ls(&all, all.info, NULL);//by passing the adress of info will it auto matically set all to it?
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