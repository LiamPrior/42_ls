/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:37:47 by lprior            #+#    #+#             */
/*   Updated: 2018/05/05 23:11:54 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info  *ft_ls(t_env *all, char *path, t_info *info)//send path as heap alsways. initial is sent as stack
{
    DIR             *type;
    struct dirent   *file;
    
    if ((type = opendir(path)) == NULL)
    {
        ft_error(2, path);
        return NULL;
    }
    while ((file = readdir(type)))
    {
        all->type = ft_strjoin2(path, file->d_name);
        // free(all->type);
        if ((ft_strncmp(file->d_name, ".", 1) == 0 && IFa == true) || NOTDOT)
            info = ft_create_node(all, info, all->type, file->d_name);
        else
            continue;
            // if (i++ == 1)
            //     while(1);
        // free(info->path);
        // free(info->name);
        // free(all->type);
        // printf("before recurse info[%p]\ninfo->sub[%p]\ninfo->name[%p]\ninfo->path[%p]\ninfo->color[%p]\npath[%p]\ntype[%p]\nfile->d_name[%p]\n", info, info->sub, info->name, info->path, info->color, path, type, file->d_name);
        // sleep (5);
        if (DRPERMS && ((!IFa && NOTDOT) || (IFa && DOTCMP && ISDOT)))
            info->sub = ft_ls(all, all->type, info->sub);
        else if (info)
            info->sub = NULL;
        // free(all->type);
        // printf("after recurse\n");
        // sleep (5);   
            // if (all->type)
            //     free(all->type);
        // free(all->type);//i need to free something in info struct
        // free(info->sub);
        // free(info->next);
        // free(info->prev);
        // free(info->name);//
        // free(info->path);//
        // free(info->color);//
        // free(info->data);
        // free(info);
        // printf("here\n");
        // sleep (5);
    }
    closedir(type);
    while (info && info->prev != NULL)
        info = info->prev;
        // sleep(10);
    return (info);
}

void    ft_parse_paths(int argc, char **argv, t_env *all)
{
    all->i = 0;
    if (argv[all->x] && argv[all->x][all->i] != '-')
    {
        all->paths[all->px] = ft_strnew(ft_strlen(argv[all->x]) + 1);
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
                    ft_error(0, &argv[all->x][1]);
            all->i++;
        }
    }
    else
        return ;
    ft_toggle_options(argc, argv, all);
}

void ft_check_paths(t_env *all)  
{
    struct stat     *info;

    all->px = 0;
    if (!(all->paths[all->px]))
    {
        all->paths[all->px] = ft_strnew(2);
        all->paths[all->px][all->px] = '.';
        all->paths[all->px + 1] = NULL;
    }
    while (all->paths[all->px])
    {
        info = (struct stat *)malloc(sizeof(struct stat));
        ft_check_file(all, info);
        free(info);
        all->px++;
    }
    while (all->args && all->args->prev != NULL)
        all->args = all->args->prev;
    while (all->dargs && all->dargs->prev != NULL)
        all->dargs = all->dargs->prev;
    all->dargs = all->dargs ? ft_init_merge(all, all->dargs) : all->dargs;
    ft_make_files(all);
    all->x = 0;
    all->i = 0;
    return ;
}

int     main(int argc, char **argv)
{
    t_env all;
    
    ft_init(&all, argc);
    ft_toggle_options(argc, argv, &all);
    ft_parse_paths(argc, argv, &all);
    ft_check_paths(&all);
    if (all.options.r)
        all.dargs = ft_goto_end(&all, all.dargs);
    while (all.dargs)
    {
        if (!(all.info = ft_ls(&all, all.dargs->name, all.info)))
        {
            all.dargs = all.options.r ? all.dargs->prev : all.dargs->next;
            continue ;
        }
        all.info = ft_init_merge(&all, all.info);
        ft_display(&all, all.info);
        if (all.dargs->next || (all.dargs->prev && all.options.r))
            write(1, "\n", 1);
        all.run = true;
        free(all.dargs);
        all.dargs = all.options.r ? all.dargs->prev : all.dargs->next;
        all.info = NULL;
    }
    ft_free_lists(&all);
    // sleep(10);
    return (0);
}
