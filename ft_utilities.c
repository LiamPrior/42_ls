/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:10:51 by lprior            #+#    #+#             */
/*   Updated: 2018/04/27 18:39:07 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info *ft_split(t_info *head)
{
    t_info *fast;
    t_info *slow;
    t_info *temp;
    
    fast = head;
    slow = head;
    printf("fast = [%s]\n", fast->name);
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = NULL;
    printf("slow = [%s]\n", temp->name);
    return (temp);
}

void    ft_error(int i, char *str)
{
    if (i == 0)
        ft_printf("ls: USAGE ./ft_ls (-R)(-a)(-t)(-l)(-r)!\n");
    else if (i == 1)
        ft_printf("ls: %s: No such file or directory\n", str);
    exit(0);
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
	return (seconds > 0 ? 1 : 0);//may need = sign
}
