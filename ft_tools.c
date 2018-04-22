/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:29:55 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/21 23:23:15 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_error(int i, char *str)
{
    if (i == 0)
        ft_printf("ls: USAGE ./ft_ls (-R)(-a)(-t)(-l)(-r)!\n");
    else if (i == 1)
        ft_printf("ls: %s: No such file or directory\n", str);
    exit(0);
}

void ft_init_2d(t_env *all, int argc)
{
    int i;

    i = 0;
    all->paths = (char **)malloc(sizeof(char *) * argc);
    while (i < argc)
        all->paths[i++] = NULL;
}

void    ft_init(t_env *all, int argc)
{
    all->options.R = false;;
    all->options.a = false;
    all->options.t = false;
    all->options.l = false;
    all->options.r = false;
    all->info = (t_info *)malloc(sizeof(t_info));
    all->info->sub = NULL;
    all->info->next = NULL;
    all->info->prev = NULL;
    all->info->path = NULL;
    all->info->name = NULL;
    all->dir = NULL;
    ft_init_2d(all, argc);
    all->i = 0;
    all->x = 0;
    all->px = 0;
}

// void    ft_create_node(t_env *all, char *path)
// {
//     t_info *cur;
//     t_info *prev;

//     cur = all->info;
//     while (cur && cur->next != NULL)
//         cur = cur->next;
//     // you have the last one in list

//     if (cur == NULL)
//     {
//         cur = (t_info *)malloc(sizeof(t_info));
//         cur->path = ft_strcur(ft_strlen(path));
//         ft_strcpy(cur->path, path);
//     }
//     if (cur->next == NULL)
//     {
//         cur->next = (t_info *)malloc(sizeof(t_info));
//         cur->path = ft_strcur(ft_strlen(path));
//         ft_strcpy(cur->path, path);
//     }
//     prev = cur;
//     cur = cur->next;
//     cur->prev = prev;
//     cur->next = NULL;
// }

// t_info    *ft_create_node(t_env *all, char *path, struct dirent *file)//send in a link instead of whole thing
// {
//     t_info *new;
//     t_info *cur;

//     new = (t_info *)malloc(sizeof(t_info));
//     new->path = ft_strnew(ft_strlen(path);
//     new->name = ft_strnew(ft_strlen(file->d_name);
//     ft_strcpy(new->name, file->d_name);
//     ft_strcpy(new->path, path);
//     new->next = NULL;
//     new->sub = NULL;
//     new->prev = NULL; 
//     if (all->info == NULL)
//         all->info = new;
//     else
//     {
//         cur = all->info;
//         while (cur->next != NULL)
//             cur = cur->next;
//         cur->next = new;
//         new->prev = cur;
//     }
//     return (new);
// }

t_info  *ft_create_node(t_info *info, char *path, struct dirent *file)
{
    t_info *new;
    t_info *cur;

    new = (t_info *)malloc(sizeof(t_info));
    new->name = ft_strdup(file->d_name);
    new->path = ft_strdup(path);//so this is creating dirty memory some how
    printf("new->path = [%s]\n", new->path);
    new->next = NULL;
    new->sub = NULL;
    new->prev = NULL;    
    if (info == NULL)
        info = new;
    else
    {
        cur = info;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = new;
        new->prev = cur;
    }
    // printf("%p path: [%s]\nnew->path = [%s] new->name = [%s]\n\n",  new,  path, new->path, new->name);
    return (new);
}
// t_info  *ft_create_node(t_info *info, char *path, struct dirent *file)
// {
//     t_info *new;
//     t_info *cur;
//     int     p;

//     p = ft_strlen(path);
//     new = (t_info *)malloc(sizeof(t_info));
//     new->name = ft_strnew(ft_strlen(file->d_name));//so this is creating dirty memory some how
//     new->path = ft_strnew(ft_strlen(path));
//     // new->path[p] = '\0';
//     new->name = ft_strcpy(new->name, file->d_name);
//     new->path = ft_strcpy(new->path, path);
//     // printf("new->name = [%s]", new->name);
//     // printf("           new->path = [%s]\n", new->path);
//     new->next = NULL;
//     new->sub = NULL;
//     new->prev = NULL;    
//     if (info == NULL)
//         info = new;
//     else
//     {
//         cur = info;
//         while (cur->next != NULL)
//             cur = cur->next;
//         cur->next = new;
//         new->prev = cur;
//     }
//     // printf("new->path = [%s] new->name = [%s]\n", new->path, new->name);
//     return (new);
// }