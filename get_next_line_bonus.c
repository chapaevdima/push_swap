/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatasha <anatasha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:05:37 by anatasha          #+#    #+#             */
/*   Updated: 2022/03/09 16:14:50 by anatasha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*my_line(char *piece)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (piece[i] && piece[i] != '\n')
		i++;
	if (piece[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (0);
	while (j < i)
	{
		line[j] = piece[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*my_read(int fd, char *piece)
{
	char	res[BUFFER_SIZE + 1];
	int		len;

	len = 1;
	while (len && !my_end(piece))
	{
		len = read(fd, res, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		res[len] = '\0';
		piece = my_strjoin(piece, res);
	}
	return (piece);
}

char	*del_start(char *piece)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (piece[i] && piece[i] != '\n')
		i++;
	if (piece[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(piece) - i + 2));
	j = 0;
	while (piece[i])
		res[j++] = piece[i++];
	res[j] = 0;
	free(piece);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*piece;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	piece = my_read(fd, piece);
	if (!piece)
		return (NULL);
	line = my_line(piece);
	if (!ft_strlen(line))
	{
		free (line);
		if (piece)
		{
			free (piece);
			piece = NULL;
		}
		return (NULL);
	}
	piece = del_start(piece);
	return (line);
}
