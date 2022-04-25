/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:05:40 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/09 16:15:00 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	my_end(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen( const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_strjoin(char *s1, char *s2)
{
	char		*res;
	size_t		i;
	size_t		len;

	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	res = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[++i])
		res[i] = ((char *)s1)[i];
	len = 0;
	while (s2[len])
		res[i++] = ((char *)s2)[len++];
	res[i] = '\0';
	free(s1);
	return (res);
}
