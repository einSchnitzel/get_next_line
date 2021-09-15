/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:07:46 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/15 13:47:31 by smetzler         ###   ########.fr       */
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
	buffer = NULL;
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

//copy text from tonext to helper and return 
//copy after '\n' to tonext and copy helper to tonext, so that only string after '\n' is left
//free helper and line

char	*ft_prepnext(char **tonext, int location, int size)
{
	char	*helper;
	char	*buff;
	int		length;

	length = ft_strlen(*tonext);
	helper = NULL;
	buff = NULL;
	//printf("location %d length %d size %d strlen tonext %d\ntonext %.30s \n", location, length, size, ft_strlen(*tonext), *tonext);
	if (length < 1 || size == -1 || tonext[0] == '\0' || tonext == NULL)
		ft_free(tonext);
	else
	{
		//PRINT_HERE(buff, buff);
		if (location <= 0 && *tonext[0] != '\n')
		{
			buff = ft_strndup(*tonext, 0, length);
			ft_free(tonext);
			return (buff);
		}
		else
		{
			if (location < 0)
				location = 1;
			helper = ft_strndup(*tonext, 0, location + 1);
			//PRINT_HERE(helper, helper);
			buff = ft_strndup(*tonext, location + 1, length - location);
			ft_free(tonext);
			*tonext = ft_strndup(buff, 0, length - location);
			ft_free(&buff);
		}
	}
	return (helper);
}

char	*get_next_line(int fd)
{
	static char	*tonext = NULL;
	char		*line;
	int			location;
	ssize_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 500)
		return (NULL);
	line = NULL;
	if (tonext == NULL)
		tonext = ft_calloc(1, '\0');
	location = ft_strchr(tonext, '\n', 0);
	while (location == -1 && location != -100)
	{
		line = ft_calloc(BUFFER_SIZE + 1, 1);
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
	return (ft_prepnext(&tonext, location, size));
}
//If last line empty file == 0 it s the end of string
//if read returns less than buffer size but is > than 0 it is the last line

// realloc instead of join