/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:29:48 by lprior            #+#    #+#             */
/*   Updated: 2018/02/18 14:28:06 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long int n)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
	return ;
}

void	ft_print_putnbr(long long int n, int *res)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_print_putstr("-9223372036854775808", res);
		return ;
	}
	if (n < 0)
	{
		ft_print_putchar('-', res);
		n *= -1;
	}
	if (n < 10)
	{
		ft_print_putchar(n + 48, res);
		return ;
	}
	ft_print_putnbr(n / 10, res);
	ft_print_putchar(n % 10 + 48, res);
	return ;
}
