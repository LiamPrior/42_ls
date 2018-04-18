/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:51:41 by lprior            #+#    #+#             */
/*   Updated: 2017/10/05 17:57:05 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2 && *str1 && *str2)
	{
		str2++;
		str1++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
