/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:29:14 by lprior            #+#    #+#             */
/*   Updated: 2018/02/18 19:38:16 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_char_tool(t_flags *tools)
{
	if (tools->prec < tools->len && tools->prec >= 0)
		tools->len = tools->prec;
	if (tools->prec >= 0 || (tools->width >= 0 && tools->prec != -100))
		tools->width -= tools->len;
}

void	ft_parse_int_tools(t_flags *tools, long int number)
{
	char *length;

	length = ft_itoa(number);
	if (number == 0 && tools->prec >= 1)
		tools->len = 0;
	else
		tools->len = ft_strlen(length);
	free(length);
	if (number < 0)
		tools->len--;
	if (tools->prec != -100)
		tools->prec -= tools->len;
	if (tools->prec >= 0)
		tools->width -= (tools->prec + tools->len);
	else
		tools->width -= tools->len;
	if (tools->positive == 1 || number < 0)
		tools->width--;
	if (tools->prec >= 0)
		tools->zeros = 0;
	if (tools->space == 1 && tools->width < 1 && number > 0)
		tools->width = 1;
	if (number < 0)
		tools->space = 0;
}

void	ft_parse_unsigned_int_tools(t_flags *tools, unsigned long long int num)
{
	if (tools->prec == -100 || tools->space == 1 || tools->prec >= 0)
		tools->zeros = 0;
	if ((tools->prec == -100 || tools->prec == 0) && num == 0)
		tools->width += 1;
	if ((tools->brand == 'x' || tools->brand == 'X') && (tools->hashtag == 1))
		tools->width -= 2;
	if ((tools->brand == 'o' || tools->brand == 'O') && tools->hashtag == 1)
		tools->width -= 1;
	if (tools->prec > 0 && (tools->len < tools->prec))
		tools->width -= tools->prec;
	else if (tools->prec == -100 || tools->prec == 0)
		tools->width -= 1;
	else
		tools->width -= tools->len;
	if (tools->prec != -100 && tools->prec >= 0)
		tools->prec -= tools->len;
	if (tools->positive == 1)
		tools->width -= 1;
}

/*
**if (tools->prec > 0 && (tools->len < tools->prec)) //tools->brand == 'x'
**||  tools->brand == 'X'
**tools->width -= tools->prec;
*/
