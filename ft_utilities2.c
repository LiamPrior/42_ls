/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:10:50 by lprior            #+#    #+#             */
/*   Updated: 2018/05/05 15:07:30 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_info(char *perms, t_info *head, struct passwd *usr, struct group *grp)
{
    perms = ft_strnew(1);
    ft_get_perms(head, perms);
    ft_printf("%d ", head->data->st_nlink);
    grp = getgrgid(head->data->st_gid);
    usr = getpwuid(head->data->st_uid);
    ft_printf("%s  ", usr->pw_name); 
    ft_printf("%s ", grp->gr_name);
    ft_printf("%6d ", head->data->st_size);
    ft_print_time(head);
}

void ft_check_file(t_env *all, struct stat *info)
{
    if (ft_strcmp(all->paths[all->px], ".") != 0)
        lstat(all->paths[all->px], info);
    if (lstat(all->paths[all->px], info) || (!S_ISDIR(info->st_mode) && !S_ISREG(info->st_mode) 
    && !S_ISCHR(info->st_mode) && !S_ISBLK(info->st_mode) 
        && !S_ISFIFO(info->st_mode) && !S_ISLNK(info->st_mode)
            && !S_ISSOCK(info->st_mode) && ft_strcmp(all->paths[all->px], ".")))
            {
                ft_error(1, all->paths[all->px]);
                all->paths[all->px] = NULL;
            }
    else if (all->paths[all->px] && ft_strcmp(all->paths[all->px], ".") && !S_ISDIR(info->st_mode))
        all->args = ft_create_node(all, all->args, all->paths[all->px], all->paths[all->px]);
    else if (all->paths[all->px] && (!ft_strcmp(all->paths[all->px], ".") || S_ISDIR(info->st_mode)))
        all->dargs = ft_create_node(all, all->dargs, all->paths[all->px], all->paths[all->px]);
    else
        free(all->paths[all->px]);
}

t_info *ft_goto_end(t_env *all, t_info *head)
{
    t_info *ptr;
    
    ptr = head;
    while (head)
    {
        ptr = head;
        if (head && all->options.R == true && head->sub != NULL)
            head->sub = ft_goto_end(all, head->sub);
        head = head->next;
    }
    return (ptr);
}

void ft_make_files(t_env *all)
{
    if (all->args)
    {
        all->args = ft_init_merge(all, all->args);
        all->tot = false;
        ft_display(all, all->args);
        all->tot = true;
        if (all->dargs)
            write(1, "\n", 1);
    }   
}

void printer(t_env *all, t_info *head)
{
    t_info *ptr;
    char *temp;

    ptr = head;
    ft_print_path(all, ptr);
    while (ptr)
    {
        ft_printf("%s%s%s", ptr->color, ptr->name, NORMAL);
        // if (all->args == NULL)
            ft_printf("\n");
        ptr = all->options.r ? ptr->prev : ptr->next;
    }
}