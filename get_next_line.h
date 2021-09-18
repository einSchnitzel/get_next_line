/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 09:42:31 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/18 14:00:36 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_var {
	char		*line;
	int			location;
	ssize_t		size;
}	t_vars;

char	*get_next_line(int fd);
char	*ft_makereturn(char **tonext, int location);
char	*ft_calloc(size_t size, char filler);
char	*ft_prepnext(char **tonext, int location, int size);
void	ft_free(char **line);
int		ft_strlen(char *str);
int		ft_strchr(char *tonext, char c, int flag);
char	*ft_strnjoin(char *previous, char *line, int size);
char	*ft_strndup(char *s1, int start, int length);

#endif