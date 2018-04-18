/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:34:47 by lprior            #+#    #+#             */
/*   Updated: 2018/02/17 23:14:31 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_otoa(unsigned long int number)
{
	char			*print;
	unsigned int	i;

	i = 0;
	print = ft_strnew(24);
	if (number < i)
		return ("errno: Unsigned Only!");
	if (number == 0)
	{
		print[i] = '0';
		i++;
	}
	while (number)
	{
		print[i] = (number % 8) + 48;
		number /= 8;
		i++;
	}
	print[i] = '\0';
	return (ft_strrev(print));
}

char	*ft_ptoa(unsigned long int number, t_flags *tools)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_strnew(12);
	if (number == 0)
		print[i] = '0';
	while (number && tools->brand == 'p')
	{
		print[i++] = "0123456789abcdef"[number % 16];
		number /= 16;
	}
	return (ft_strrev(print));
}

char	*ft_htoa(unsigned long int number, t_flags *tools)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_strnew(18);
	if (number == 0)
		print[i] = '0';
	while (number && tools->brand == 'x')
	{
		print[i++] = "0123456789abcdef"[number % 16];
		number /= 16;
	}
	while (number && tools->brand == 'X')
	{
		print[i++] = "0123456789ABCDEF"[number % 16];
		number /= 16;
	}
	return (ft_strrev(print));
}

char	*ft_ullitoa(unsigned long long int number)
{
	unsigned long long int		tmp;
	unsigned int				count;
	char						*str;

	count = 1;
	tmp = number;
	while (tmp /= 10)
		count++;
	if (!(str = ft_strnew(count)))
		return (NULL);
	while (count--)
	{
		str[count] = number >= 10 ? (number % 10) + 48 : number + 48;
		number /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

char	*ft_uitoa(unsigned int nbr)
{
	unsigned int	tmp;
	unsigned int	count;
	char			*str;

	count = 1;
	tmp = nbr;
	while (tmp /= 10)
		count++;
	if (!(str = ft_strnew(count)))
		return (NULL);
	while (count--)
	{
		str[count] = nbr >= 10 ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
