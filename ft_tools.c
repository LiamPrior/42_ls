/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:29:55 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/29 22:04:40 by lprior           ###   ########.fr       */
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

void    ft_get_perms(t_info *haed, char *perms)
{
    if (S_IFBLK(data->st_mode))
        perms = ft_strjoin(perms, "b");
    else if (S_IFCHR(data->st_mode))
        perms = ft_strjoin(perms, "c");
    else if (_ISDIR(data->st_mode))
       perms = ft_strjoin(perms, "d");
    else if (S_ISLNK(data->st_mode))
       perms = ft_strjoin(perms, "l");
    else if (S_IFSOCK(data->st_mode))
        perms = ft_strjoin(perms, "s");
    else if (S_IFIFO(data->st_mode))
        perms = ft_strjoin(perms, "p");
    else
       perms = ft_strjoin(perms, "-");
    perms = S_IRUSR(head->data->st_mode) ? ft_strjoin(perms, "r") : ft_strjoin(temp, "-");
    perms = S_IWUSR(head->data->st_mode) ? ft_strjoin(perms, "w") : ft_strjoin(temp, "-");
    perms = S_IXUSR(head->data->st_mode) ? ft_strjoin(perms, "x") : ft_strjoin(temp, "-");
    perms = S_IRGRP(head->data->st_mode) ? ft_strjoin(perms, "r") : ft_strjoin(temp, "-");
    perms = S_IWGRP(head->data->st_mode) ? ft_strjoin(perms, "w") : ft_strjoin(perms, "-");
    perms = S_IXGRP(head->data->st_mode) ? ft_strjoin(perms, "x") : ft_strjoin(perms, "-");
    perms = S_IROTH(head->data->st_mode) ? ft_strjoin(perms, "r") : ft_strjoin(perms, "-");
    perms = S_IWOTH(head->data->st_mode) ? ft_strjoin(perms, "w") : ft_strjoin(perms, "-");
    perms = S_IXOTH(head->data->st_mode) ? ft_strjoin(perms, "x") : ft_strjoin(perms, "-");
    return (perms);
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

t_info  *ft_create_node(t_env *all, t_info *info, char *path, struct dirent *file)
{
    t_info *new;
    t_info *cur;
    struct stat     *data;

    data = (struct stat *)malloc(sizeof(struct stat));
    new = (t_info *)malloc(sizeof(t_info));
    new->name = ft_strdup(file->d_name);
    new->path = ft_strdup(path);
    ft_stat_color(data, new);
    new->time = all->options.t ? data->st_mtimespec : new->time;  
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
    // free(data);
    return (new);
}
