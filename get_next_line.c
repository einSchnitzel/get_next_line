/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:07:46 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/18 14:38:43 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
** read BUFFER_SIZE bytes
** if a newline is in buffer, save the things from after newline into const char
** add the content of the following buffer into the const char
*/
char	*ft_calloc(size_t size, char filler)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = NULL;
	buffer = (char *) malloc(size + 1);
	if (buffer == NULL)
		return (NULL);
	while (i < size)
	{
		buffer[i] = filler;
		i++;
	}
	return (buffer);
}

/*
** copy text from tonext before newline to helper for return(output)
** copy after newline to buff and from buff to tonext for next gnl call
*/
char	*ft_makereturn(char **tonext, int location)
{
	int		length;
	char	*buff;
	char	*helper;

	helper = NULL;
	buff = NULL;
	length = ft_strlen(*tonext);
	if (location < 0)
		location = 1;
	helper = ft_strndup(*tonext, 0, location + 1);
	buff = ft_strndup(*tonext, location + 1, length - location);
	ft_free(tonext);
	*tonext = ft_strndup(buff, 0, length - location);
	ft_free(&buff);
	return (helper);
}

/*
** if tonext is empty free and return NULL
** if there is a string and no \n found and no \n at 0 safe to buff and free
** if there is content divide the string on \n, see ft_makereturn
*/
char	*ft_prepnext(char **tonext, int location, int size)
{
	char	*buff;
	int		length;

	length = ft_strlen(*tonext);
	buff = NULL;
	if (length < 1 || size == -1 || *tonext[0] == '\0' || !tonext)
		ft_free(tonext);
	else
	{
		if (location <= 0 && *tonext[0] != '\n')
		{
			buff = ft_strndup(*tonext, 0, length);
			ft_free(tonext);
		}
		else
		{
			buff = ft_makereturn(tonext, location);
		}
	}
	return (buff);
}

void	ft_initvalues(char **tonext, t_vars *vars)
{
	vars->line = ft_calloc(BUFFER_SIZE, '\0');
	if (vars->line == NULL)
	{
		ft_free(tonext);
		return ;
	}
	vars->location = ft_strchr(*tonext, '\n', 0);
	vars->size = 0;

	return ;
}

/*
** static, variable to keep the content after newline for the next call
** line, content read
** location where \n is
** size, return of read
** stay in the loop as long as no newline is read from buffer -1 (or error -100)
*/
char	*get_next_line(int fd)
{
	static char	*tonext = NULL;
	t_vars		vars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tonext == NULL)
		tonext = ft_calloc(1, '\0');
	if (tonext == NULL)
		return (NULL);
	ft_initvalues(&tonext, &vars);
	while (vars.location == -1 && vars.location != -100)
	{
		vars.size = read(fd, vars.line, BUFFER_SIZE);
		if (vars.size <= 0)
			break ;
		vars.line[vars.size] = '\0';
		tonext = ft_strnjoin(tonext, vars.line, vars.size);
		vars.location = ft_strchr(tonext, '\n', 1);
	}
	ft_free(&vars.line);
	return (ft_prepnext(&tonext, vars.location, vars.size));
}
