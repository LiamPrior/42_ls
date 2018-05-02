/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:10:50 by lprior            #+#    #+#             */
/*   Updated: 2018/05/01 23:42:42 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
// void    ft_displaytwo(t_env *all, t_info *head)
// {
//     t_info *ptr;

//     ptr = head;
//     // printf("HERE\n");
//     // if (all->options.r == false && all->options.R == false)
//         while (ptr)
//         {
//             ft_printf("%s%s%s\n", ptr->color, ptr->name, NORMAL);
            // if (ptr && all->options.R == true && ptr->sub != NULL)
            //     ft_displaytwo(all, ptr->sub);
//             ptr = ptr->next;
//         } 
// }

t_info *ft_goto_end(t_env *all, t_info *ptr)
{
    while (ptr->next)
    {
        if (ptr->next && all->options.R == true && ptr->sub != NULL)
            ptr->sub = ft_goto_end(all, ptr->sub);
        ptr = ptr->next;
    }
    return (ptr);
}
