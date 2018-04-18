/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:18:30 by lprior            #+#    #+#             */
/*   Updated: 2017/09/25 14:16:44 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n-- > 0)
	{
		if (((char *)src)[i] == c)
		{
			((char *)dst)[i] = ((char *)src)[i];
			return (&dst[i + 1]);
		}
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (NULL);
}
