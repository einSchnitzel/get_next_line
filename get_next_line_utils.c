/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:10:38 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/08 16:54:04 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		free(line[i]);
		i++;
	}
}

int	ft_strchr(char *tonext, char c)
{
	int		i;

	i = 0;
	while (tonext[i] != '\0' || tonext[i] != '\n')
	{
		if (tonext[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strnjoin(char *tonext, char *line, int size)
{
	char	*snew;
	int		n1;
	int		n2;
	int		i;

	i = 0;
	if (tonext == NULL || line == NULL)
		return (NULL);
	n1 = ft_strlen(tonext);
	n2 = ft_strlen(line);
	snew = (char *) malloc(n1 + n2 + 1);
	if (snew == NULL || !tonext || !line)
		return (NULL);
	ft_copys1(tonext, snew, i, n1);
	i = 0;
	while (line[i] != '\0')
	{
		snew[n1 + i] = line[i];
		i++;
	}
	snew[n1 + n2] = '\0';
	return (snew);
}
