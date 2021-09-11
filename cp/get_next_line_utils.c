/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:10:38 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/11 17:07:35 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **line)
{
	free(*line);
	*line = NULL;
}

int	ft_strchr(char *s, char c, int flag)
{
	int		i;

	if (flag == 1 && !s)
		return (-100);
	i = 0;
	while (s[i] && s)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnjoin(char *previous, char *line, int size)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(previous);
	if (line[0] == '\0')
		return (NULL);
	joined = malloc(size + j + 1);
	if (!joined)
		return (NULL);
	while (i <= size + j)
	{
		if (i < j && previous != NULL)
			joined[i] = previous[i];
		if (i >= j)
			joined[i] = line[i - j];
		i++;
	}
	joined[i] = '\0';
	if (previous)
		ft_free(&previous);
	return (joined);
}

char	*ft_strndup(char *s1, int start, int length)
{
	char	*thecopy;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	thecopy = malloc(length + 1);
	if (thecopy == NULL)
		return (NULL);
	while (i < length && s1 && s1[i] != '\0')
	{
		thecopy[i] = s1[i + start -1];
		i++;
	}
	thecopy[i] = '\0';
	return (thecopy);
}
