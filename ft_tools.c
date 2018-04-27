/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:29:55 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/26 20:24:04 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
    all->options.R = false;
    all->options.a = false;
    all->options.t = false;
    all->options.l = false;
    all->options.r = false;
    all->info = NULL;
    all->type = NULL;
    ft_init_2d(all, argc);
    all->i = 0;
    all->x = 0;
    all->px = 0;
}

t_info  *ft_create_node(t_info *info, char *path, struct dirent *file)
{
    t_info *new;
    t_info *cur;

    new = (t_info *)malloc(sizeof(t_info));
    new->name = ft_strdup(file->d_name);
    new->path = ft_strdup(path);
    new->color = NULL;
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
    return (new);
}
