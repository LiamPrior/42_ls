/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:03:15 by lprior            #+#    #+#             */
/*   Updated: 2018/04/28 21:02:52 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


//i still need to be able to handle if they pass in more tahn one arg and time shit.

// t_info *ft_split(t_info *head)
// {
//     t_info *fast;
//     t_info *slow;
//     t_info *temp;
    
//     fast = head;
//     slow = head;
//     while (fast->next && fast->next->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     temp = slow->next;
//     slow->next = NULL;
//     return (temp);
// }
// int			sort_time(t_list *a, t_list *b)
// {
// 	long diff;
// 	long ndiff;

// 	diff = a->time.tv_sec - b->time.tv_sec;
// 	if (!diff)
// 	{
// 		ndiff = a->time.tv_nsec - b->time.tv_nsec;
// 		if (!ndiff)
// 			return (ft_strcmp(a->name, b->name) <= 0 ? 1 : 0);
// 		return (ndiff >= 0 ? 1: 0);
// 	}
// 	return (diff >= 0 ? 1 : 0);
// }
t_info *ft_time_sort(t_env *all, t_info *first, t_info *second)
{
    if (!(first))
        return (second);
    if (!(second))
        return (first);
    // printf("here\n");
    if (ft_get_time(first, second))//if the time is 0 that means the last modified file was second
    {
        first->next = ft_time_sort(all, first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return (first);
    }
    else//if its a 1 that means the first file was modified last
    {
        second->next = ft_time_sort(all, first, second->next);
        second->next->prev = first;
        second->prev = NULL;
        return (second);
    }
}

t_info *ft_merge_links(t_env *all, t_info *first, t_info *second)
{
    if (!(first))
        return (second);
    if (!(second))
        return (first);
        // printf("%sfirst [%s] and second [%s]\n%s", "\x1B[34m", first->name, second->name, "\x1B[0m");
    if (first->name[all->i] < second->name[all->i])
    {
        // printf("%ssecond is greater = [%s] > [%s]%s\n", "\x1b[32m", second->name, first->name, "\x1B[0m");
        all->i = 0;
        first->next = ft_merge_links(all, first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return (first);
    }
    else if (first->name[all->i] > second->name[all->i]) 
    {
        all->i = 0;
        // printf("%sfirst is greater = [%s] > [%s]%s\n", "\x1B[31m", first->name, second->name, "\x1B[0m");
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

t_info *ft_merge_sort(t_env *all, t_info *head)//okay so my split isnt working rn because for some reasoon it isnt recusing so what you need to do is print pointer with theat printf and see why its not recursing
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
