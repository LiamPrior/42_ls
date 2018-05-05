/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:10:51 by lprior            #+#    #+#             */
/*   Updated: 2018/05/04 22:01:53 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info    *ft_init_merge(t_env *all, t_info *head)
{
    t_info *ptr;

    if (head)
         head = ft_merge_sort(all, head);
    ptr = head;
    while (ptr != NULL)
    { 
        if (ptr->sub)
            ptr->sub = ft_init_merge(all, ptr->sub);
        ptr = ptr->next;
    }
    return (head);
}

void    ft_stat_color(struct stat *data, t_info *new)
{
    lstat(new->path, data);
    new->data = data;
    if (S_ISDIR(data->st_mode))
        new->color = strdup("\x1B[35m");
    else if (data->st_mode & S_IXUSR && !S_ISLNK(data->st_mode))
        new->color = ft_strdup("\x1B[31m");
    else if (S_ISLNK(data->st_mode))
        new->color = ft_strdup("\x1B[33m");
    else
        new->color = ft_strdup("\x1B[37m");
}

t_info *ft_split(t_info *head)
{
    t_info *fast;
    t_info *slow;
    t_info *temp;
    
    fast = head;
    slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = NULL;
    return (temp);
}

void    ft_error(int i, char *str)
{
    if (i == 0)
    {
        ft_printf("ls: illegal option -- %s\nusage: ls ./ft_ls (-R)(-a)(-t)(-l)(-r)!\n", str);
        exit (0);
    }
    else if (i == 1)
        ft_printf("ls: [%s]\n: No such file or directory\n", str);
    else if (i == 2)
    {
        ft_printf("ls: %s: Permission denied\n", str);//this needs to be fixed
        // exit (0);
    }
}

int     ft_get_time(t_info *first, t_info *second)
{
    long seconds;
    long nano_seconds;

	seconds = first->time.tv_sec - second->time.tv_sec;
    if (!seconds)
	{
		nano_seconds = first->time.tv_nsec - second->time.tv_nsec;
		if (!nano_seconds)
			return (ft_strcmp(first->name, second->name) <= 0 ? 1 : 0);
		return (nano_seconds > 0 ? 1: 0);
	}
	return (seconds > 0 ? 1 : 0);
}
