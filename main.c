/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:07:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/10 10:23:15 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int	main(void)
{
	int		fd;
	char*	text;

	fd = open("test.txt", O_RDONLY);

	text = get_next_line(fd);
	printf("%s", text);
	free(text);
	text = NULL;
}