/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:07:46 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/10 17:37:12 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
** read BUFFER_SIZE bytes
** if newline in buffer, save the things from after newline into const char
** add the content of the following buffer into the const char
*/

char	*ft_calloc(int size, char filler)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char *) malloc(size);
	if (buffer == NULL)
		return (NULL);
	while (i <= size)
	{
		buffer[i] = filler;
		i++;
	}
	return (buffer);
}

//copy after '\n' to helper and copy helper to tonext, so that only afte '\n' is left
//copy text from tonext to next_line and return 
//free helper and line

char	*ft_prepnext(char **tonext, int location, int size)
{
	char	*next_line;
	char	*helper;
	int		i;

	if (size <= 0 || !*tonext)
	{
		if (*tonext != NULL)
			return (*tonext);
		return (NULL);
	}
	i = ft_strlen(*tonext);
	helper = ft_strndup(*tonext, location + 1, i - location);
	next_line = ft_strndup(*tonext, 0, location);
	printf("next_line return %s\n", next_line);
	i = ft_strlen(helper);
	*tonext = ft_strndup(helper, 0, i);
	if (helper != NULL)
		ft_free(&helper);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*tonext;
	char		*line;
	int			location;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 500)
		return (NULL);
	line = NULL;
	if (tonext == NULL)
		tonext = ft_calloc(BUFFER_SIZE + 1, '\0');
	location = ft_strchr(tonext, '\n');
	while (location == -1)
	{
		line = ft_calloc(BUFFER_SIZE + 1, '\0');
		if (line == NULL)
			return (NULL);
		size = read(fd, line, BUFFER_SIZE);
		if (size <= 0)
			break ;
		tonext = ft_strnjoin(tonext, line, size);
		location = ft_strchr(tonext, '\n');
	}
	if (line != NULL)
		ft_free(&line);
	return (ft_prepnext(&tonext, location, size));
}
