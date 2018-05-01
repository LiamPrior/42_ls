/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:58:57 by lprior            #+#    #+#             */
/*   Updated: 2018/04/30 20:59:20 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//okay so i can print all the things 

void printer(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    while (ptr)
    {
        ft_printf("%s%s%s\n", ptr->color, ptr->name, NORMAL);
        ptr = all->options.r ? ptr->prev : ptr->next;
    }
}

void    ft_print_long(t_env *all, t_info *head)//i need to get total memory blocks!!!!!!!!
{
    char *perms;
    struct group *grp;
    struct passwd *usr;

    while (head)
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
        ft_printf("%s%s%s\n", head->color, head->name, NORMAL);
        head = all->options.r == true ? head->prev : head->next;
    }
}

void ft_recursive_print(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    all->options.l == true ? ft_print_long(all, ptr) : printer(all, ptr);
    while (ptr && all->options.R == true)
    {
        if (S_ISDIR(ptr->data->st_mode))
        {
            ft_printf("\n%s:\n", ptr->path);//////////////////////////////////////
            if (ptr->sub != NULL)
                ft_recursive_print(all, ptr->sub);
        }
        ptr = all->options.r == true ? ptr->prev : ptr->next;
    }
}

void    ft_display(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    ptr = all->options.r == true ? ft_goto_end(all, ptr) : ptr;
    if (all->options.R == true)
        ft_recursive_print(all, ptr);//may need to add if statement for -R
    if (all->options.l == true)//gonna not even have this later!
        ft_print_long(all, ptr);
}