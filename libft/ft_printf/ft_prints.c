/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:11:08 by lprior            #+#    #+#             */
/*   Updated: 2018/02/18 19:33:25 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(int start, int end, char *format, int *res)
{
	int i;

	i = 0;
	while (i < start && format[i])
		i++;
	while (i < end)
	{
		ft_print_putchar(format[i], res);
		i++;
	}
}

void	ft_print_zeros(t_flags *tools)
{
	while (tools->width-- >= 1)
	{
		if (tools->zeros == 1)
			ft_print_putchar('0', &(tools->retrn));
		else if (tools->zeros == 0)
			ft_print_putchar(' ', &(tools->retrn));
		if (tools->width == 0)
			tools->width = -100;
	}
}

void	ft_print_prec(t_flags *tools)
{
	if (tools->prec != -100)
		while (tools->prec-- >= 1)
			ft_print_putchar('0', &(tools->retrn));
}

void	ft_print_address(t_flags *tools, unsigned long long int number)
{
	if (tools->brand == 'x' && number != 0)
		ft_print_putstr("0x", &(tools->retrn));
	else if ((tools->brand == 'o' || tools->brand == 'O') &&
			tools->prec - tools->len < 0 && number != 0)
		ft_print_putchar('0', &(tools->retrn));
	else if (tools->brand == 'X' && number != 0)
		ft_print_putstr("0X", &(tools->retrn));
	tools->hashtag = 0;
}
