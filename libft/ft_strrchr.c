/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:23:54 by lprior            #+#    #+#             */
/*   Updated: 2017/09/25 19:11:55 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *temp;

	temp = str;
	temp = temp + ft_strlen(str);
	while (*temp != (char)c && temp != str)
		temp--;
	if (*temp == (char)c)
		return ((char *)temp);
	return (0);
}
