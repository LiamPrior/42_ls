/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:01:10 by lprior            #+#    #+#             */
/*   Updated: 2017/09/26 14:24:59 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = ft_strlen(dst);
	while (dst[i])
		i++;
	if (size < i)
		return (ft_strlen((char *)src) + size);
	else
	{
		while (i < size - 1 && src[j])
			dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (x + ft_strlen((char *)src));
}
