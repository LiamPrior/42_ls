/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:03:15 by lprior            #+#    #+#             */
/*   Updated: 2018/05/06 19:36:01 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info  *ft_time_sort(t_env *all, t_info *first, t_info *second)
{
	if (!(first))
		return (second);
	if (!(second))
		return (first);
	if (ft_get_time(first, second))
	{
		first->next = ft_time_sort(all, first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return (first);
	}
	else
	{
		second->next = ft_time_sort(all, first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return (second);
	}
}

t_info  *ft_merge_links(t_env *all, t_info *first, t_info *second)
{
	if (!(first))
		return (second);
	if (!(second))
		return (first);
	if (first->name[all->i] < second->name[all->i])
	{
		all->i = 0;
		first->next = ft_merge_links(all, first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return (first);
	}
	else if (first->name[all->i] > second->name[all->i]) 
	{
		all->i = 0;
		second->next = ft_merge_links(all, first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return (second);
	}
	else
	{
		all->i++;
		return (ft_merge_links(all, first, second));
	}
}

t_info  *ft_merge_sort(t_env *all, t_info *head)
{
	t_info *second;
	t_info *ptr;

	all->i = 0;
	ptr = head;
	if (!head || !head->next)
		return head;
	second = ft_split(head);
	head = ft_merge_sort(all, head);
	second = ft_merge_sort(all, second);
	return (all->options.t == true ? ft_time_sort(all, head, second) 
		: ft_merge_links(all, head, second));
}
