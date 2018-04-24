/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:03:15 by lprior            #+#    #+#             */
/*   Updated: 2018/04/23 16:27:54 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


//i still need to be able to handle if they pass in more tahn one arg and time shit.

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

t_info *ft_merge_links(t_env *all, t_info *first, t_info *second)
{
    // printf("here1\n");
    if (!(first))
        return (second);
    if (!(second))
        return (first);
    // printf("[%zu][%zu]\n", ft_strlen(first->name), ft_strlen(second->name));
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

t_info *ft_merge_sort(t_env *all, t_info *head)
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
    ptr = head;
    while (ptr && all->options.R == true)
    {
        if (ptr->sub != NULL)
            ft_merge_sort(all, ptr->sub);
        ptr = ptr->next;
    }
    return (ft_merge_links(all, head, second));
}