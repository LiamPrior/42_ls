/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:23:14 by lprior            #+#    #+#             */
/*   Updated: 2018/04/28 16:02:32 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *s2;

	s2 = ft_strnew(ft_strlen(src) + 1);
	if (s2)
		return (ft_strcpy(s2, (char *)src));
	return (NULL);
}
