/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:23:14 by lprior            #+#    #+#             */
/*   Updated: 2017/09/18 13:59:32 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *s2;

	s2 = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (s2)
		return (ft_strcpy(s2, (char *)src));
	return (NULL);
}
