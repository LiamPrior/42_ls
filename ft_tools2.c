/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 18:02:04 by lprior            #+#    #+#             */
/*   Updated: 2018/05/06 20:02:56 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_operate(t_env *all, t_info *temp)
{
	all->info = ft_init_merge(all, all->info);
	ft_display(all, all->info);
	if (temp->next || (temp->prev && all->options.r))
		write(1, "\n", 1);
	all->run = true;
}
