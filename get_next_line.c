/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:07:46 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/08 00:30:31 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
** read BUFFER_SIZE bytes
** if newline in buffer, save the things from after newline into const char
** add the content of the following buffer into the const char
*/

char	*get_next_line(int fd)
{
	static char	*tonext;
	char		*line;
	int			location;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0|| OPEN_MAX)
		return (NULL);
	line = NULL;
	location = ft_strchr(tonext, '\n', 1);
	while (location == -1)
	{
		line = malloc(BUFFER_SIZE + 1);
		if (line == NULL)
			return (NULL);
		size = read(fd, line, BUFFER_SIZE);
		if (size <= 0)
			break ;
		tonext = ft_strnjoin(tonext, line, size);
		location = ft_strchr(tonext, '\n');
		ft_free(&line);
	}
	ft_free(&line);
	return (ft_prepnext(tonext, location, size));
}
