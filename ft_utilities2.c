/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:10:50 by lprior            #+#    #+#             */
/*   Updated: 2018/05/03 11:34:39 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info *ft_goto_end(t_env *all, t_info *head)//okay so the problem is that it gets to the last node and wont recurse and go to the end of the sub linked list
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
