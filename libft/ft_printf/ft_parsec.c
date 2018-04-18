/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:36:04 by lprior            #+#    #+#             */
/*   Updated: 2018/02/18 17:56:09 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type2(char format, t_flags *tools, va_list ap)
{
	if (format == 'o' || format == 'O' || format == 'u' || format == 'U'
		|| format == 'x' || format == 'X')
	{
		tools->brand = format;
		ft_print_unsigned_int(tools, ap);
	}
	else if (format == 'c' || format == 'C')
	{
		tools->brand = format;
		tools->len = 1;
		ft_print_char(tools, ap);
	}
	else if (format == '%')
	{
		tools->brand = format;
		ft_print_percent(tools);
	}
	else if (format == 'b')
	{
		tools->brand = 'b';
		ft_print_binary(ap);
	}
	else
		tools->brand = -1;
}

void	ft_check_type(char form, t_flags *tools, va_list ap)
{
	if (form == 's' && tools->arg != 4)
	{
		tools->brand = form;
		ft_print_string(tools, ap);
	}
	else if (form == 'S' || (form == 'C' && tools->arg == 7) || form == 's')
	{
		tools->brand = form;
		if (form == 'C')
			ft_print_wchar(tools, ap);
		else if (form == 'S' || form == 's')
			ft_print_wchar_str(tools, ap);
	}
	else if (form == 'p')
	{
		tools->brand = form;
		ft_print_pointer(tools, ap);
	}
	else if (form == 'd' || form == 'i' || form == 'D')
	{
		tools->brand = form;
		ft_print_int(tools, ap);
	}
	else
		ft_check_type2(form, tools, ap);
}
