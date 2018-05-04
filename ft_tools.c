/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:29:55 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/03 21:13:24 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_print_time(t_info *head)
{
    char *timer;
    int i;

    timer = ctime(&head->time.tv_sec);
    timer += 4;
    i = ft_strlen(timer);
    i -= 9;
    timer[i] = '\0';
    ft_printf("%s ", timer);
}

void ft_init_2d(t_env *all, int argc)
{
    int i;

    i = 0;
    all->paths = (char **)malloc(sizeof(char *) * argc);
    while (i < argc)
        all->paths[i++] = NULL;
}

void    ft_get_perms(t_info *head, char *perms)
{
    if (S_ISDIR(head->data->st_mode))
       perms = ft_strjoin(perms, "d");
    else if (S_ISCHR(head->data->st_mode))
        perms = ft_strjoin(perms, "c");
    else if (S_ISBLK(head->data->st_mode))
        perms = ft_strjoin(perms, "b");
    else if (S_ISLNK(head->data->st_mode))
       perms = ft_strjoin(perms, "l");
    else if (S_ISSOCK(head->data->st_mode))
        perms = ft_strjoin(perms, "s");
    else if (S_ISFIFO(head->data->st_mode))
        perms = ft_strjoin(perms, "p");
    else
       perms = ft_strjoin(perms, "-");
    perms = S_IRUSR & head->data->st_mode ? ft_strjoin(perms, "r") : ft_strjoin(perms, "-");
    perms = S_IWUSR & head->data->st_mode ? ft_strjoin(perms, "w") : ft_strjoin(perms, "-");
    perms = S_IXUSR & head->data->st_mode ? ft_strjoin(perms, "x") : ft_strjoin(perms, "-");
    perms = S_IRGRP & head->data->st_mode ? ft_strjoin(perms, "r") : ft_strjoin(perms, "-");
    perms = S_IWGRP & head->data->st_mode ? ft_strjoin(perms, "w") : ft_strjoin(perms, "-");
    perms = S_IXGRP & head->data->st_mode ? ft_strjoin(perms, "x") : ft_strjoin(perms, "-");
    perms = S_IROTH & head->data->st_mode ? ft_strjoin(perms, "r") : ft_strjoin(perms, "-");
    perms = S_IWOTH & head->data->st_mode ? ft_strjoin(perms, "w") : ft_strjoin(perms, "-");
    perms = S_IXOTH & head->data->st_mode ? ft_strjoin(perms, "x") : ft_strjoin(perms, "-");
    ft_printf("%s  ", perms);
    free(perms);
}

void    ft_init(t_env *all, int argc)
{
    all->options.R = false;
    all->options.a = false;
    all->options.t = false;
    all->options.l = false;
    all->options.r = false;
    all->run = true;
    all->info = NULL;
    all->args = NULL;
    all->type = NULL;
    all->dargs = NULL;
    all->tot = true;
    ft_init_2d(all, argc);
    all->i = 0;
    all->x = 0;
    all->px = 0;
    all->total = 0;
}

t_info  *ft_create_node(t_env *all, t_info *info, char *path, char *name)//struct dirent *file)//so i changed this so i dont hvae to pass file from ft_check_paths!
{
    t_info *new;
    t_info *cur;
    struct stat     *data;

    data = (struct stat *)malloc(sizeof(struct stat));
    new = (t_info *)malloc(sizeof(t_info));
    new->name = ft_strdup(name);
    new->path = ft_strdup(path);
    ft_stat_color(data, new);
    new->time = data->st_mtimespec;  
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
    // printf("all names = [%s]\n", new->name);
    return (new);
}
