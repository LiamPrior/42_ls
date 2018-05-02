/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:58:57 by lprior            #+#    #+#             */
/*   Updated: 2018/05/01 23:54:28 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void printer(t_env *all, t_info *head)
{
    t_info *ptr;
    char *temp;

    ptr = head;
    temp = ft_strdup(ptr->path);
    if ((all->dargs->next || all->dargs->prev) && all->run == true)// !all->dargs->prev)
        while(ptr->path[all->i])
        {
            if (ptr->path[all->i] == '/')
                if (ptr->path[all->i + 1])
                {
                    temp[all->i] = '\0';
                    ft_printf("%s:\n", temp);
                    all->run = false;
                }
            all->i++;
        }
        free(temp);
    while (ptr)
    {
        ft_printf("%s%s%s\n", ptr->color, ptr->name, NORMAL);
        ptr = all->options.r ? ptr->prev : ptr->next;
    }
}

void ft_get_total(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    while (ptr)
    {
        all->total += ptr->data->st_blocks;
        ptr = ptr->next;
    }
}

void    ft_print_long(t_env *all, t_info *head)//i need to get total memory blocks!!!!!!!!
{
    char *perms;
    struct group *grp;
    struct passwd *usr;
    char *link;

    ft_get_total(all, head);
    ft_printf("total %d\n", all->total);
    all->total = 0;
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
        if (S_ISLNK(head->data->st_mode))//put this in its own function
        {
            link = ft_strnew(ft_strlen(head->path) + 1);
            readlink(head->path, link, 1024);
            ft_printf("%s%s%s", head->color, head->name, NORMAL);
            ft_printf(" -> ");
            ft_printf("%s\n", link);
        }
        else
            ft_printf("%s%s%s\n", head->color, head->name, NORMAL);
        head = all->options.r == true ? head->prev : head->next;
    }
}

void ft_recursive_print(t_env *all, t_info *head)//okay this isnt going to work because libft isnt a node so it just puts all other file args in through merge list with the rest because the others arnt in a sub liist i cahnged a few things!
{
    t_info *ptr;

    ptr = head;
    all->options.l == true ? ft_print_long(all, ptr) : printer(all, ptr);
    while (ptr && all->options.R == true)
    {
        if (S_ISDIR(ptr->data->st_mode))// && all->run == false)
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
    // printer(all, ptr);
    // ptr = all->options.r == true ? ft_goto_end(all, ptr) : ptr;
    // all->options.r == true ? ft_goto_end(all, ptr) : ;
    if (all->options.r == true)
        ptr = ft_goto_end(all, ptr);
    if (all->options.R == false && all->options.l == false)
        printer(all, ptr);
    else if (all->options.R == true)
        ft_recursive_print(all, ptr);
    else if (all->options.l == true)
        ft_print_long(all, ptr);
    //may need to add if statement for -R
    // if (all->options.l == true)//gonna not even have this later!
    //     ft_print_long(all, ptr);
}