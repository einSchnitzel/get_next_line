/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:07:46 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/11 12:57:22 by smetzler         ###   ########.fr       */
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
	char	*helper;
	int		i;

	if ((size <= 0 && !*tonext)|| location == -100)
	{
		PRINT_HERE("tonext", tonext);
		if (*tonext != NULL)
			return (*tonext);
		PRINT_HERE("some",&size);
		return (NULL);
	}
	if (location == -1)
		location = ft_strlen(*tonext);
	i = ft_strlen(*tonext);
	helper = ft_strndup(*tonext, location, i - location + 1);
	next_line = ft_strndup(*tonext, 0, location + 1);
	printf("next_line return %s\n", next_line);
	i = ft_strlen(helper);
	*tonext = ft_strndup(helper, 0, i);
	PRINT_HERE("helper", helper);
	PRINT_HERE("next_line", next_line);
	PRINT_HERE("i", &i);
	if (helper != NULL)
		ft_free(&helper);
	return (tonext);
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
	location = ft_strchr(tonext, '\n', 0);
	while (location == -1 && location != -100) //
	{
		line = ft_calloc(BUFFER_SIZE + 1, '\0');
		if (line == NULL)
			return (NULL);
		size = read(fd, line, BUFFER_SIZE);
		if (size <= 0)
			break ;
		tonext = ft_strnjoin(tonext, line, size);
		location = ft_strchr(tonext, '\n', 1);
		ft_free(&line);
	}
	ft_free(&line);
	PRINT_HERE("line", &line);
	return (ft_prepnext(&tonext, location, size));
}
