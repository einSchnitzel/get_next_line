/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 23:59:22 by smetzler          #+#    #+#             */
/*   Updated: 2021/08/25 21:37:43 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char* s1)
{
	char	*thecopy;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(s1);
	thecopy = malloc(sizeof(char *) * (length + 1));
	if (thecopy == NULL)
		return (NULL);
	while (i <= length)
	{
		thecopy[i] = s1[i];
		i++;
	}
	thecopy[i] = '\0';
	return (thecopy);
}

char*	ft_get_line(int fd, char* newline, char* address)
{
	int		size;
	char*	helper;
	size = 1;
	
	while (address != '\n' || address != '\0')
	{
		helper = malloc(size);
		helper = ft_strdup(newline);
		free(newline);
		size++;
		newline = malloc(size + 1);
		newline = ft_strdup(helper);
		newline[size] = read(fd, address, 1);
		address++;
		free(helper);
	}
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			pos;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = ft_get_line(fd, line, save);
	ft_get_size(line);
	return(line);
}
