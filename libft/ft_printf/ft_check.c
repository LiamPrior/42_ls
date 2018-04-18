/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:26:23 by lprior            #+#    #+#             */
/*   Updated: 2018/02/17 23:05:27 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_check_signed_int(t_flags *tools, va_list ap)
{
	if (tools->brand == 'd' || tools->brand == 'i')
		return ((int)va_arg(ap, void*));
	return (0);
}

unsigned long long int	ft_check_unsigned_int(t_flags *tools, va_list ap)
{
	if (tools->brand == 'U' || tools->brand == 'O')
		return ((unsigned long long int)va_arg(ap, void*));
	else if (tools->brand == 'u' || tools->brand == 'o' || tools->brand == 'X'
			|| tools->brand == 'x')
		return ((unsigned int)va_arg(ap, void*));
	return ((unsigned long long int)NULL);
}

unsigned long long int	ft_sort_unsigned_args(t_flags *tools, va_list ap)
{
	if (tools->arg == 1)
		return ((size_t)va_arg(ap, size_t));
	else if (tools->arg == 2)
		return ((uintmax_t)va_arg(ap, void*));
	else if (tools->arg == 3)
		return ((unsigned short int)va_arg(ap, void*));
	else if (tools->arg == 4)
		return ((unsigned long int)va_arg(ap, void*));
	else if (tools->arg == 5)
		return ((unsigned char)va_arg(ap, void*));
	else if (tools->arg == 6)
		return ((unsigned long long int)va_arg(ap, void*));
	else
		return (ft_check_unsigned_int(tools, ap));
}

long long int			ft_sort_signed_args(t_flags *tools, va_list ap)
{
	if (tools->arg == 1)
		return (va_arg(ap, size_t));
	else if (tools->arg == 2)
		return (va_arg(ap, intmax_t));
	else if (tools->arg == 3)
		return ((short int)va_arg(ap, void*));
	else if (tools->arg == 4 || tools->brand == 'D')
		return ((long int)va_arg(ap, void*));
	else if (tools->arg == 5)
		return ((char)va_arg(ap, void*));
	else if (tools->arg == 6)
		return ((long long int)va_arg(ap, void*));
	else
		return (ft_check_signed_int(tools, ap));
}
