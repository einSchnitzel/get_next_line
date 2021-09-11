/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:07:46 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/11 18:03:50 by smetzler         ###   ########.fr       */
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

//copy text from tonext to helper and return 
//copy after '\n' to tonext and copy helper to tonext, so that only string after '\n' is left
//free helper and line



char	*ft_prepnext(char **tonext, int location, int size)
{
	char	*helper;
	char	*next;
	int		i;

	//PRINT_HERE("tonext", &tonext);
	if ((size <= 0 && !*tonext)|| location == -1) 
	{
		//PRINT_HERE("tonext", tonext);
		if (*tonext[0] != '\0' && *tonext)
		{
			//PRINT_HERE(*tonext, *tonext);
			return (*tonext);// do if I read \0 and it is size < BUFFER_SIZE
		}
		//PRINT_HERE("some", &size);
		ft_free(tonext);
		return (NULL);
	}
	helper = NULL;
	if (location == -1)
		location = ft_strlen(*tonext);
	else
		location++;
	i = ft_strlen(*tonext) - location;
	helper = ft_strndup(*tonext, 0, location);
	if (location == ft_strlen(*tonext))
		ft_free(tonext);
	else
	{
		next = ft_strndup(*tonext, location, i);
		//ft_free(tonext);
		*tonext = next;
	}
	
	//PRINT_HERE("helper", helper);
	//PRINT_HERE("tonext", *tonext);
	//PRINT_HERE("i", &i);
	return (helper);
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
		tonext = malloc(BUFFER_SIZE + 1);
	location = ft_strchr(tonext, '\n', 0);
	while (location == -1 && location != -100) //
	{
		line = ft_calloc(BUFFER_SIZE + 1, 1);
		if (line == NULL)
			return (NULL);
		size = read(fd, line, BUFFER_SIZE); // if returns less than buffer size but is > than 0 it is the last line
		//PRINT_HERE(line, &line);
		//printf("size %d\n", size);
		if (size < 1)
			break ;
		tonext = ft_strnjoin(tonext, line, size);
		location = ft_strchr(tonext, '\n', 1);
		ft_free(&line);
	}
	ft_free(&line);
	//PRINT_HERE(tonext, &tonext);
	return (ft_prepnext(&tonext, location, size));
}
//If last line empty file == 0 it s the end of string