/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:07:13 by lprior            #+#    #+#             */
/*   Updated: 2018/05/06 20:44:32 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*ft_free_info(t_env *all, t_info *head)
{
	t_info *temp;

	temp = head;
	while (temp)
	{
		if (temp->sub)
			temp->sub = ft_free_info(all, temp->sub);
		free(temp);
		temp = IFr ? temp->next : temp->prev;
	}
	return (head);
}

void	ft_free_lists(t_env *all)
{
	t_info *temp;

	temp = all->dargs;
	while (temp->prev)
	{
		free(temp->name);
		free(temp->path);
		free(temp->color);
		free (temp);
		temp = temp->next;
	}
	free(all->dargs);
	ft_free_info(all, all->info);
	free(all->info);
}
