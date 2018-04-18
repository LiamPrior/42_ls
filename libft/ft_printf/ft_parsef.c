/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:21:44 by lprior            #+#    #+#             */
/*   Updated: 2018/02/18 17:00:58 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_fwap(char *format, int *i, t_flags *tools)
{
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == ' ' ||
			format[*i] == '#' || format[*i] == '0')
		ft_check_flags(format, i, tools);
	ft_check_args(format, i, tools);
	ft_check_width(format, i, tools);
	ft_check_prec(format, i, tools);
	ft_check_args(format, i, tools);
}

void	ft_parse_flags2(char *format, int *i, t_flags *tools)
{
	if (format[*i] != '\0')
	{
		if (format[*i] == 'h')
			ft_check_fwap(format, i, tools);
		else if (format[*i] == 'l')
			ft_check_fwap(format, i, tools);
		else if (format[*i] == 'j')
			ft_check_fwap(format, i, tools);
		else if (format[*i] == 'z')
			ft_check_fwap(format, i, tools);
		else if (format[*i] == 'k')
			ft_check_fwap(format, i, tools);
	}
}

void	ft_parse_flags(char *form, int *i, t_flags *tools, va_list ap)
{
	(*i)++;
	if (form[*i] != '\0')
	{
		if (form[*i] == '.')
			ft_check_fwap(form, i, tools);
		else if (form[*i] == '-')
			ft_check_fwap(form, i, tools);
		else if (form[*i] == '+')
			ft_check_fwap(form, i, tools);
		else if (form[*i] == ' ')
			ft_check_fwap(form, i, tools);
		else if (form[*i] == '#')
			ft_check_fwap(form, i, tools);
		else if (form[*i] == '0')
			ft_check_fwap(form, i, tools);
		else if (form[*i] >= '0' && form[*i] <= '9')
			ft_check_fwap(form, i, tools);
		else
			ft_parse_flags2(form, i, tools);
	}
	ft_check_type(form[*i], tools, ap);
}
