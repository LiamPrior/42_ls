/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:22:14 by lprior            #+#    #+#             */
/*   Updated: 2017/10/05 12:52:25 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_place_words(char const *s, char c, int *newi)
{
	int		i;
	char	*word;
	int		begin;

	i = 0;
	while (s[*newi] == c && s[*newi] != '\0')
		(*newi)++;
	begin = *newi;
	while (s[*newi] != c && s[*newi] != '\0')
		(*newi)++;
	if (!(word = ft_strnew(*newi - begin)))
		return (NULL);
	while (begin < *newi)
		word[i++] = s[begin++];
	word[i] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		i;
	int		count;
	int		k;

	k = 0;
	count = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	i = 0;
	if (!(strings = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	while (i < count)
		strings[i++] = ft_place_words(s, c, &k);
	strings[i] = 0;
	return (strings);
}
