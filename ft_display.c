/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:58:57 by lprior            #+#    #+#             */
/*   Updated: 2018/04/23 20:37:12 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_display(t_env *all, t_info *head)//okay so this is broken
{
    t_info *ptr;

    ptr = head;
    while (ptr)
    {
        ft_printf("[%s]\n", ptr->path);
        if (ptr && all->options.R == true && ptr->sub != NULL)
            ft_display(all, ptr->sub);
        ptr = ptr->next;
    } 
}