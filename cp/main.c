/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:07:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/11 17:39:26 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void gnl(int fd, int i)
{
	char*	text;
	text = get_next_line(fd);
	printf("main%d: %s\n", i, text);
	free(text);
	text = NULL;
	return ;
}

int	main(void)
{
	int		fd;
	int		readempty;

	fd = open("test.txt", O_RDONLY);
	printf("read: %d\n", readempty);
	gnl(fd, 1);
	gnl(fd, 2);
	// gnl(fd, 3);
	// gnl(fd, 4);
	//gnl(fd, 3);
}