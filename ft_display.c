/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:58:57 by lprior            #+#    #+#             */
/*   Updated: 2018/04/26 20:35:32 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_display(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    // if (all->options.r == false && all->options.R == false)
        while (ptr)
        {
            ft_printf("%s%s%s\n", ptr->color, ptr->name, NORMAL);
            if (ptr && all->options.R == true && ptr->sub != NULL)
                ft_display(all, ptr->sub);
            ptr = ptr->next;
        } 
}