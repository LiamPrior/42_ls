/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:07:13 by lprior            #+#    #+#             */
/*   Updated: 2018/05/06 22:14:23 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
t_info	*ft_delete_node(t_env *all, t_info *curr)
{
	t_info *prev;
	t_info *next;

	prev = curr->prev;
	next = curr->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	free(curr->path);
	free(curr->name);
	free(curr->data);
	free(curr->color);
	free(curr);
	return (all->options.r ? prev : next);
}

t_info	*ft_free_info(t_env *all, t_info *head)
{
	t_info *temp;

	temp = head;
	while (temp)
	{
		ft_delete_node(all, temp);
		if (temp->sub)
			temp->sub = ft_free_info(all, temp->sub);
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
