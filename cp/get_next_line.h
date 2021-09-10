/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 09:42:31 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/10 17:37:18 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

// DEBUGGING, DELETE IT LATER
# define PRINT_HERE(var) (printf("\n at line: %d, in file: %s text: %s\n", __LINE__, __FILE__,var))

char	*get_next_line(int fd);
char	*ft_calloc(int size, char filler);
char	*ft_prepnext(char **tonext, int location, int size);
void	ft_free(char **line);
int		ft_strlen(char *str);
int		ft_strchr(char *tonext, char c);
char	*ft_strnjoin(char *tonext, char *line, int size);
char	*ft_strndup(char *s1, int start, int length);

#endif