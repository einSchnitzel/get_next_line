/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 09:42:31 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/18 14:00:29 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>


char	*get_next_line(int fd);
char	*ft_calloc(ssize_t size, char filler);
char	*ft_makereturn(char **tonext, int location);
char	*ft_prepnext(char **tonext, int location, ssize_t size);
void	ft_free(char **line);
int		ft_strlen(char *str);
int		ft_strchr(char *tonext, char c, int flag);
char	*ft_strnjoin(char *previous, char *line, ssize_t size);
char	*ft_strndup(char *s1, int start, int length);

#endif