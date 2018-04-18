/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamprior <liamprior@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:23:13 by lprior            #+#    #+#             */
/*   Updated: 2018/03/11 20:08:07 by liamprior        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_flags *tools, va_list ap)
{
	char *string;

	string = va_arg(ap, char *);
	if (ft_print_color(string) == 1)
		ft_putstr(string);
	if (string == NULL)
		string = "(null)";
	tools->len = ft_strlen(string);
	ft_parse_char_tool(tools);
	while (tools->negative == 0 && tools->width-- > 0)
		ft_print_putchar(' ', &(tools->retrn));
	while ((tools->len-- > 0) && *string && tools->prec != -100)
		ft_print_putchar(*string++, &(tools->retrn));
	while (tools->width-- > 0)
		ft_print_putchar(' ', &(tools->retrn));
}

void	ft_print_int2(t_flags *tools, long long int number, int dis)
{
	if (tools->negative == 0)
		ft_print_zeros(tools);
	if (tools->positive == 1 && number >= 0)
	{
		ft_print_putchar('+', &(tools->retrn));
		tools->positive = 0;
	}
	if (number <= -1)
	{
		ft_print_putchar('-', &(tools->retrn));
		number *= -1;
		tools->positive = 0;
	}
	ft_print_prec(tools);
	if (dis == 1 && number == 0)
	{
		if (tools->zeros == 1)
			ft_print_putchar('0', &(tools->retrn));
		else if ((IFPW) || (tools->prec == -100 && number != 0) || (IFWP))
			ft_print_putchar(' ', &(tools->retrn));
	}
	else
		ft_print_putnbr(number, &(tools->retrn));
	while (tools->width-- >= 1)
		ft_print_putchar(' ', &(tools->retrn));
}

void	ft_print_int(t_flags *tools, va_list ap)
{
	long long int	number;
	int				dis;

	number = ft_sort_signed_args(tools, ap);
	dis = (tools->prec > -1 || tools->prec == -100) ? 1 : 0;
	ft_parse_int_tools(tools, number);
	if (tools->zeros == 1 && tools->positive == 1 && number > -1)
	{
		ft_print_putchar('+', &(tools->retrn));
		tools->positive = 0;
	}
	if (tools->zeros == 1 && number <= -1)
	{
		ft_print_putchar('-', &(tools->retrn));
		number *= -1;
		tools->positive = 0;
	}
	if (tools->space == 1)
	{
		tools->width--;
		ft_print_putchar(' ', &(tools->retrn));
	}
	ft_print_int2(tools, number, dis);
}

void	ft_print_char(t_flags *tools, va_list ap)
{
	unsigned char leter;

	if (tools->brand == 'C' && tools->prec == -100)
		tools->width -= 1;
	leter = va_arg(ap, int);
	ft_parse_char_tool(tools);
	while (tools->negative == 0 && tools->width-- > 0)
	{
		if (tools->zeros == 1)
			ft_print_putchar('0', &(tools->retrn));
		else
			ft_print_putchar(' ', &(tools->retrn));
	}
	ft_print_putchar(leter, &(tools->retrn));
	while (tools->width-- > 0)
		ft_print_putchar(' ', &(tools->retrn));
}
