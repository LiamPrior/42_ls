/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:12:06 by lprior            #+#    #+#             */
/*   Updated: 2018/02/17 23:20:53 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width(char *format, int *i, t_flags *tools)
{
	char	*tmp;

	tmp = format;
	while (ft_isdigit(format[*i]) && format[*i] != '\0')
	{
		tmp += *i;
		tools->width = ft_atoi(tmp);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}

void	ft_check_flags(char *format, int *i, t_flags *tools)
{
	while (format[*i] != '\0' && (format[*i] == '-' || format[*i] == '+' ||
			format[*i] == '0' || format[*i] == '#' || format[*i] == ' '))
	{
		if (format[*i] == '-')
		{
			tools->negative = 1;
			tools->zeros = 0;
		}
		else if (format[*i] == '+')
		{
			tools->positive = 1;
			tools->space = 0;
		}
		else if (format[*i] == ' ' && tools->positive == 0)
			tools->space = 1;
		else if (format[*i] == '#')
			tools->hashtag = 1;
		else if (format[*i] == '0' && tools->negative == 0)
			tools->zeros = 1;
		(*i)++;
	}
}

void	ft_check_args(char *format, int *i, t_flags *tools)
{
	while (format[*i] != '\0' && (format[*i] == 'h' || format[*i] == 'l' ||
			format[*i] == 'z' || format[*i] == 'j' || format[*i] == 'k'))
	{
		if (format[*i] == 'z')
			tools->arg = 1;
		else if (format[*i] == 'j')
			tools->arg = 2;
		else if (format[*i] == 'h')
		{
			if (tools->arg == 3)
				tools->arg = 5;
			else
				tools->arg = 3;
		}
		else if (format[*i] == 'l')
		{
			if (tools->arg == 4)
				tools->arg = 6;
			else
				tools->arg = 4;
		}
		else if (format[*i] == 'k')
			tools->arg = 7;
		(*i)++;
	}
}

void	ft_check_prec(char *format, int *i, t_flags *tools)
{
	char *tmp;

	tmp = format;
	if (format[*i] == '.')
		(*i)++;
	else
		return ;
	if (format[*i] != ft_isdigit(format[*i]))
		tools->prec = -100;
	if (format[*i] != '\0' && (format[*i] == '-' ||
		ft_isdigit(format[*i])))
	{
		tools->prec = ft_atoi(&(tmp[*i]));
		while (ft_isdigit(tmp[*i]))
			(*i)++;
	}
}
