/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:33:40 by lprior            #+#    #+#             */
/*   Updated: 2018/05/03 16:36:45 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen((char *)s1)
		+ ft_strlen((char *)s2) + 1)))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

// char *ft_strjoin2(char const *s1, char const *s2)//okay so path is fucked up so that means that sometimes your merge sort wont even see some dirs as dirs because the path is filled with dirty memopry
// {//so in char** add a slash to the end of each thing
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	if (!(str = (char *)malloc(ft_strlen((char *)s1)
// 		+ ft_strlen((char *)s2) + 2)))//member
// 		return (NULL);
// 	str = ft_strcpy(str, s1);
// 	str[ft_strlen(str) + 1] = '\0'; 
// 	str[ft_strlen(str)] = '/';
// 	printf("str = [%s]\n", str);
// 	str = ft_strcat(str, s2);
// 	// str[ft_strlen(str)] = '/';.
// 	// str[ft_strlen(str) + 1] = '\0';
// 	// free(s1);
// 	// printf("in strjoin[%s]\n", str);
// 	return (str);
// }
char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*path;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	path = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	while (s1[i])
	{
		path[i] = s1[i];
		i++;
	}
	path[i++] = '/';
	while (s2[j])
		path[i++] = s2[j++];
	path[i] = '\0';
//	free(s1);
	return (path);
}
// char *ft_strjoin2(char const *s1, char const *s2)//okay so path is fucked up so that means that sometimes your merge sort wont even see some dirs as dirs because the path is filled with dirty memopry
// {//so in char** add a slash to the end of each thing
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	if (!(str = (char *)malloc(ft_strlen((char *)s1)
// 		+ ft_strlen((char *)s2) + 1)))//member
// 		return (NULL);
// 	str = ft_strcpy(str, s1);
// 	str[ft_strlen(str) + 1] = '\0'; 
// 	str[ft_strlen(str)] = '/';
// 	str = ft_strcat(str, s2);
// 	// str[ft_strlen(str)] = '/';.
// 	// str[ft_strlen(str) + 1] = '\0';
// 	// free(s1);
// 	// printf("in strjoin[%s]\n", str);
// 	return (str);
// }