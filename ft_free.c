/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:07:13 by lprior            #+#    #+#             */
/*   Updated: 2018/05/05 17:13:43 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info *ft_free_info(t_env *all, t_info *head)
{
    while (head)
    {
        free(head);
        if (head->sub)
            head->sub = ft_free_info(all, head->sub);
        head = IFr ? head->next : head->prev;//may need to change this
    }
    return (head);
}

void ft_free_lists(t_env *all)
{
    if (all->args)
        while (all->args)
        {
            free(all->args);
            all->args = all->args->next;
        }
    if (all->dargs)
    {
        while (all->dargs->prev)
        {
            free(all->dargs->name);
            free(all->dargs->path);
            free(all->dargs->color);
            // free(time);
            free (all->dargs);
            all->dargs = all->dargs->prev;
        }
    }
    if (all->info)
        ft_free_info(all, all->info);
    
}