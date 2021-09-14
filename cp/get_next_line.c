/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:07:46 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/14 14:46:25 by smetzler         ###   ########.fr       */
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
	char	*buff;
	int		length;

	length = ft_strlen(*tonext);
	//printf("location %d length %d size %d strlen tonext %d\ntonext %s \n", location, length, size, ft_strlen(*tonext), *tonext);
	// PRINT_HERE(*tonext,*tonext);
	if (*tonext && location >= 0) //1st to last -1 line
	{
		helper = ft_strndup(*tonext, 0, location + 1);
		buff = ft_strndup(*tonext, location + 1, length - location);
		free(*tonext);
		printf("BUFFER IS : %s\n", buff);
		// PRINT_HERE(buff, buff);
		*tonext = ft_strndup(buff, 0, length - location);
		// PRINT_HERE(*tonext, *tonext);
	}
	else if (location == -1 ||(size < BUFFER_SIZE && size >= 0)) // last line
	{
		helper = ft_strndup(*tonext, 0, length);
		ft_free(tonext);
	}
	else
		helper = NULL;
	printf("tonext");
	PRINT_HERE(*tonext, *tonext);
	// printf("helper");
	// PRINT_HERE(helper, helper);
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
	// printf("tonext");
	//PRINT_HERE(tonext, tonext);
	location = ft_strchr(tonext, '\n', 0);
	// printf("location %d\nstart while\n",location);
	while (location == -1 && location != -100)
	{
		line = ft_calloc(BUFFER_SIZE + 1, 1);
		if (line == NULL)
			return (NULL);
		size = read(fd, line, BUFFER_SIZE);
		if (size < 1)
			break ;
		tonext = ft_strnjoin(tonext, line, size);
		location = ft_strchr(tonext, '\n', 1);
		// printf("location %d tonext %s\n", location, tonext);
		ft_free(&line);
	}
	ft_free(&line);
	PRINT_HERE(tonext, tonext);
	return (ft_prepnext(&tonext, location, size));
}
//If last line empty file == 0 it s the end of string
//if read returns less than buffer size but is > than 0 it is the last line