/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:03:15 by lprior            #+#    #+#             */
/*   Updated: 2018/04/24 23:08:32 by lprior           ###   ########.fr       */
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
    // printf("temp = [%s]\n", temp->path);
    slow->next = NULL;
    return (temp);
}

t_info *ft_merge_links(t_env *all, t_info *first, t_info *second)
{
    if (!(first))
    {
        // printf("here %s\n", second->name);
        return (second);
    }
    if (!(second))
    {
        // printf("here2 %s\n", first->name);
        return (first);
    }
    // printf("first = [%s] second = [%s]\n", first->path, second->path);
    // sleep(5);
    // printf("first = [%s]  second = [%s]\n", first->name, second->name);
    if (first->name[all->i] < second->name[all->i])
    {
        all->i = 0;
        // printf("first1 = [%s]  second = [%s]\n", first->name, second->name);
        first->next = ft_merge_links(all, first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        // printf("return  first = %s\n", first->name);
        return (first);
    }
    else if (first->name[all->i] > second->name[all->i]) 
    {
        all->i = 0;
        // printf("first2 = [%s]  second2 = [%s]\n", first->name, second->name);
        second->next = ft_merge_links(all, first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        // printf("return second = %s\n", second->name);
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
    // printf("ptr = [%s]\n", ptr->path);
    if (!head || !head->next)
        return head;
    second = ft_split(head);
    head = ft_merge_sort(all, head);
    second = ft_merge_sort(all, second);
    ptr = head;
    while (ptr && all->options.R == true)//for some reason it doesnt work if the next node in line of a lesser value
    {
        if (ptr->sub != NULL)
             ptr->sub = ft_merge_sort(all, ptr->sub);
        ptr = ptr->next;
    }
    // printf("before here\n");
  return (ft_merge_links(all, head, second));
}
