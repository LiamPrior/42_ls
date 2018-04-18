/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:18:35 by lprior            #+#    #+#             */
/*   Updated: 2018/02/18 17:02:34 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_print_putstr(char const *s, int *res)
{
	while (*s)
		ft_print_putchar(*s++, res);
}
