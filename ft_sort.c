/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:03:15 by lprior            #+#    #+#             */
/*   Updated: 2018/04/22 23:35:29 by lprior           ###   ########.fr       */
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
        char *str;
        char *str2;

        str = first->name;
        str2 = second->name;
    // printf("[%zu][%zu]\n", ft_strlen(first->name), ft_strlen(second->name));
//   while (all->i < ft_strlen(first->name) && all->i < ft_strlen(second->name))
//    {
        // printf("here3\n");
        if (first->name[all->i] < second->name[all->i])
        {
            // printf("here4\n");
            all->i = 0;
            first->next = ft_merge_links(all, first->next, second);
            first->next->prev = first;
            first->prev = NULL;
            return (first);
        }
        else if (first->name[all->i] > second->name[all->i]) 
        {
            // printf("here5\n");
            all->i = 0;
            second->next = ft_merge_links(all, first, second->next);
            second->next->prev = second;
            second->prev = NULL;
            return (second);
        }
        else
            all->i++;
        ft_merge_links(all, first, second);
    //     // printf("shoudlnt be here\n");
    //     // printf("here6\n");
    // }
    // printf("here7\n");
    // ft_error(3, "ughhh");
    // return (NULL);
}

t_info *ft_merge_sort(t_env *all, t_info *head)
{
    t_info *second;

    all->i = 0;
    if (!head || !head->next)
        return head;
    second = ft_split(head);
    // printf("[%zu]\n", ft_strlen(head->name));
    // printf("[%zu]\n", ft_strlen(second->name));
    // Recur for left and right halves
    head = ft_merge_sort(all, head);
    second = ft_merge_sort(all, second);
    // Merge the two sorted halves
    // if (all->options.t == false)
        return (ft_merge_links(all, head, second));
    // else
    // return (ft_merge_links2(all, head, second));
}